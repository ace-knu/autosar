# -*- coding: UTF-8 -*-
Import('env')

import os
import cdt
import common

files = cdt.CdtProject().get_filtered_static_files_n_paths(env)

externalObjects = Object(source=files['externalFile'], INCLUDE_PATH=files['externalPath'])

for i in range(len(files['internalFile'])):
    env['OBJECTS'].insert(0, files['internalFile'][i])
    

libraryFile = []
#internalObjects = []
#if len(files['internalFile']):
#    internalObjects = Object(source=files['internalFile']) 
    
    #internalObjects = Object(source=files['internalFile'],
    #                         INCLUDE_PATH=[files['internalPath'], files['externalPath'], ])
    #env['LIBRARY_FILE'] = os.path.join(env['DEBUG_DIR'], 'lib' + env['PROJECT'])
    #libraryFile = Library(source=internalObjects, target=env['LIBRARY_FILE'])
    #libraryFile = []
    #env['LIBRARY_FILE'] += env['LIBSUFFIX']
    #env['LIBPATH'] += [env['DEBUG_DIR']]


env.Alias('LIBRARY', libraryFile)
env['LIBS'] += common.get_library_name(libraryFile, env['LIB_INSTALL_DIR'])
if os.path.exists(env['LIB_INSTALL_DIR']):
    env['LIBPATH'] += [env['LIB_INSTALL_DIR']]

#binary = Program(target=env['DEBUG_DIR'] + os.sep + env['PROJECT'], source=[env['OBJECTS'], externalObjects])
binary = Program(target=env['DEBUG_DIR'] + os.sep + env['PROJECT'], source=[env['OBJECTS'], externalObjects])
#env.Depends(binary, libraryFile)
Alias('Compile', binary)
Clean('Compile', env['DEBUG_DIR'])