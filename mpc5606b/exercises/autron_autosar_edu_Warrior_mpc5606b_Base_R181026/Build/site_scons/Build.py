# -*- coding: UTF-8 -*-'
import subprocess
import time
import multiprocessing
import os
import sys
import shutil


def make_dir(dirname):
    if not os.path.exists(dirname):
        os.makedirs(dirname)


def get_log_filename(log_dir):
    time_str = time.strftime("%y-%m-%d_%H-%M-%S", time.localtime())
    time_filename = os.path.join(log_dir, time_str + '.log')
    last_filename = os.path.join(log_dir, 'last_build.log')
    return {'time': time_filename, 'last': last_filename}


def get_scons_path():
    # set SCONS_HOME=D:\ts_mirr\scons\scons-local-2.3.1
    try:
        scons_path = os.environ['SCONS_HOME']
    except KeyError:
        scons_path = r'D:\ts_mirr\scons\scons-local-2.3.1'
    return os.path.join(scons_path, 'scons.py')


def get_python_path():
    # set PYTHON_HOME=D:\ts_mirr\python\Portable Python 2.7.5.1\App
    try:
        python_path = os.environ['PYTHON_HOME']
    except KeyError:
        python_path = r'D:\ts_mirr\python\Portable_Python_2.7.6.1\App'
    return os.path.join(python_path, 'python.exe')


def tee_pipe(pipe, output_list):
    # map()
    # map(lambda output, context: output.write(context), output)
    for line in pipe:
        for a_output in output_list:
            a_output.write(line)
            a_output.flush()  # 에러 발생시 eclipse console 창에서 순서가 뒤죽박죽됨


from threading import Thread


def tee(infile, files):
    """Print `infile` to `files` in a separate thread."""

    def fanout(infile, files):
        if isinstance(infile, list):  # for command
            target = [' '.join(infile)+'\n']
        else:  # for stdout/stderr
            target = iter(infile.readline, '')
        for line in target:
            for f in files:
                f.write(line)
                f.flush()
        if not isinstance(infile, list):
            infile.close()

    fanout_thread = Thread(target=fanout, args=(infile, files))
    fanout_thread.daemon = True
    fanout_thread.start()
    return fanout_thread


def teed_call(cmd_args, **kwargs):
    output_files = kwargs.pop('output_files', None)
    p = subprocess.Popen(cmd_args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, **kwargs)
    threads = []
    if output_files is not None:
        threads.append(tee(cmd_args, output_files+[sys.stdout]))
        threads.append(tee(p.stdout, output_files+[sys.stdout]))
        threads.append(tee(p.stderr, output_files+[sys.stderr]))
    for t in threads:
        t.join()  # wait for IO completion
    p.wait()
    return p


def build(argument_list=None, option=None):
    if not option:
        option = {'clean': False, 'verbose': False, 'parallel': '-j' + multiprocessing.cpu_count()}
    if not argument_list:
        argument_list = ['GenerateAll', 'Compile']

    log_filename = get_log_filename('.log')
    scons_path = get_scons_path()
    python_path = get_python_path()
    make_dir('.log')
    with open(log_filename['time'], 'w') as this_time_log, open(log_filename['last'], 'w') as last_log:
        for a_argument in argument_list:
            command = [
                python_path,  # '"' + python_path + '"',
                scons_path,
                '-f.\Build\SConstruct',
                a_argument,
                option['parallel'],
            ]
            if option['verbose']:
                command += ['--debug=explain']
                command += ['--progress=ProgressCounter']

            generate_process = teed_call(command, output_files=[this_time_log, last_log])
            if 0 != generate_process.returncode:
                    sys.exit(generate_process.returncode)


def get_value_from_sconstruct(var):
    env = dict()
    with open(r'Build\SConstruct', 'r') as sconstruct:
        for a_line in sconstruct.readlines():
            if a_line.split('=')[0].rstrip() in var:
                exec(a_line)
    return env


def do_clean():
    import os
    print os.getcwd()
    if os.path.exists('.sconsign.dblite'):
        os.remove('.sconsign.dblite')
        print "os.remove('.sconsign.dblite')"
    compare_target = [
        "env['DEBUG_DIR']",  # env['DEBUG_DIR'] = 'Debug'
        "env['BSW_OUTPUT_DIR']",  # env['BSW_OUTPUT_DIR'] = os.path.join('Generated', 'Bsw_Output')
        "env['MCAL_OUTPUT_DIR']",  # env['MCAL_OUTPUT_DIR'] = os.path.join('Generated', 'Mcal_Output')
    ]
    env = get_value_from_sconstruct(compare_target)
    for a_key in env.keys():
        if os.path.exists(env[a_key]):
            shutil.rmtree(env[a_key])
            print "Delete " + env[a_key]


def handle_argument(argument_list):
    option_dict = dict()
    return_args = []
    option_dict['verbose'] = False

    for a_argument in argument_list:
        if '-verbose' in argument_list:
            option_dict['verbose'] = True
            continue
        if a_argument.startswith('-'):
            if a_argument.startswith('-j'):
                option_dict['parallel'] = a_argument
            else:
                return_args += a_argument
        elif a_argument.lower() == 'rebuild':
            do_clean()
            return_args = ['GenerateAll', 'Compile']
        elif a_argument.lower() == 'build':
            return_args = ['GenerateAll', 'Compile']
        elif a_argument.lower() == 'release':
            return_args = ['GenerateAll', 'Release']
        elif a_argument.lower() == 'test':
            return_args = ['GenerateAll', 'Test']
        else:
            return_args += [a_argument]
    try:
        option_dict['parallel']
    except KeyError:
        option_dict['parallel'] = '-j' + str(multiprocessing.cpu_count())

    return return_args, option_dict


if __name__ == "__main__":
    (arguments, options) = handle_argument(sys.argv[1:])
    build(arguments, options)
