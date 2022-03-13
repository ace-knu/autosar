Import('env')

import os
import cdt
import re
import sys

##################################

cdt.set_file_variable(env.Dir('#').path, globals())
cdt.set_file_variable('Modules_mpc5607b\Swc', globals())  # override files of IntegrationTest
cdt.set_file_variable('Test_Config', globals())  # override files of Test_Config

generated = []  # for init
env['OUTPUTDIR'] = env['BSW_OUTPUT_DIR']  # Set defalut output
##############################################################################################
try:

    # GenerateMCAL ###########################################################################
    mcalConfingOutputs = []
    mcalConfigs = [
        'Adc_Cfg.c', 'Adc_PBcfg.c', 'Can_Cfg.c', 'Can_PBcfg.c',
        'Dio_Cfg.c', 'Dio_PBcfg.c', 'Fee_Cfg.c',
        'Fls_Cfg.c', 'Fls_PBcfg.c', 'Gpt_Cfg.c', 'Gpt_PBcfg.c',
        'Icu_Cfg.c', 'Icu_PBcfg.c',
        'Mcu_Cfg.c', 'Mcu_Dmamux_LLD.c', 'Mcu_MC_Clocks_LLD.c',
        'Mcu_MC_Monitor_LLD.c', 'Mcu_MC_Power_LLD.c', 'Mcu_MC_Reset_LLD.c',
        'Mcu_MC_Modes_LLD.c', 'Mcu_PBcfg.c',
        'Port_Cfg.c', 'Port_PBcfg.c', 'Pwm_Cfg.c', 'Pwm_PBcfg.c',
        'Spi_Cfg.c', 'Spi_Lcfg.c', 'Spi_PBcfg.c', 'Wdg_CfgExt.c',
        'Wdg_43_Instance0_Cfg.c', 'Wdg_43_Instance0_Lcfg.c',
        'Wdg_43_Instance0_PBcfg.c',
    ]
    for aMcalConfig in mcalConfigs:
        mcalConfingOutputs += [os.path.join('src', aMcalConfig)]

    mcalConfigs = [
        'Adc_Cfg.h', 'Adc_CTU_ipversion.h', 'Can_Cfg.h',
        'Dio_Cfg.h', 'Fee_Cfg.h', 'Fls_Cfg.h', 'Gpt_Cfg.h', 'Icu_Cfg.h',
        'Mcu_Cfg.h',
        'modules.h', 'Port_Cfg.h', 'Pwm_Cfg.h', 'Reg_eSys_MagicCarpet.h',
        'Soc_Ips.h', 'Spi_Cfg.h', 'Wdg_Cfg.h',
    ]

    for aMcalConfig in mcalConfigs:
        mcalConfingOutputs += [os.path.join('include', aMcalConfig)]

    generateMCAL = env.GenerateMCAL(
        target=mcalConfingOutputs,
        source=[
            Ecud_Adc, Ecud_Base, Ecud_Can, Ecud_Dem_Mcal, Ecud_Dio,
            Ecud_EcuM_Mcal, Ecud_Fee, Ecud_Fls, Ecud_Gpt, Ecud_Icu,
            Ecud_Mcu, Ecud_Port, Ecud_Spi, Ecud_Wdg,
            Ecud_Pwm, Ecud_Resource,
        ],
        MCALDEFINES=[{'target': 'PA'}, {'derivate': 'XPC560XB'}],
        MCALLOADS=[
            'Mcu', 'Resource', 'Dem', 'Base', 'Can', 'Adc', 'Dio', 'Spi',
            'Gpt', 'Port', 'Wdg', 'Fee', 'Fls', 'Icu', 'Pwm', 'EcuM'
        ],
        MCALGENERATES=[
            'Mcu_TS_T2D13M10I1R0', 'Resource_TS_T2D13M10I1R0',
            'Base_TS_T2D13M10I1R0',
            'Can_TS_T2D13M10I1R0', 'Adc_TS_T2D13M10I1R0',
            'Dio_TS_T2D13M10I1R0', 'Gpt_TS_T2D13M10I1R0',
            'Port_TS_T2D13M10I1R0',
            'Fee_TS_T2D13M10I1R0', 'Fls_TS_T2D13M10I1R0',
            'Icu_TS_T2D13M10I1R0', 'Pwm_TS_T2D13M10I1R0',
            'Wdg_TS_T2D13M10I1R0', 'Spi_TS_T2D13M10I1R0',
        ],
        OUTPUTDIR=env['MCAL_OUTPUT_DIR'],
    )

    #import time
    #env.AddPreAction(generateMCAL, env.Action('Date 2014-12-31'))
    #env.AddPostAction(generateMCAL, env.Action('Date '+time.strftime("%Y-%m-%d")))
    #import atexit  # for failed generation
    #current_date = time.strftime("%Y-%m-%d")
    #atexit.register(lambda *x: os.system('Date '+ current_date))

    Alias('GenerateMCAL', generateMCAL)
    generated += [generateMCAL]
    # #################################################################################

    # GenerateHwResource###############################################################
    moduleName = 'HwResource'
    generateBSW = env.GenerateBSW(
        target=[
            'inc' + os.sep + moduleName + '.h',
        ],
        source=[
            Ecud_HwResource
        ],
        BSW_GENERATOR=HwResource,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateIoHwAb_B #############################################################
    moduleName = 'IoHwAb'
    Bswmd_IoHwAb = os.path.join('bswmd', 'Bswmd_IoHwAb.arxml')

    Bswmd_IoHwAb = env.GenerateBSW(
        target=Bswmd_IoHwAb,
        source=[
            Ecud_IoHwAb, Ecud_Os, Ecud_Port, Ecud_Dio, Ecud_Adc, Ecud_Mcu,
            Ecud_Pwm, Ecud_Icu, Ecud_Spi, Ecud_Gpt,
        ],
        BSW_GENERATOR=IoHwAb,
        BSWDEFINES='B',
    )
    Alias('Generate' + moduleName + '_B', Bswmd_IoHwAb)
    ################################################################################

    # GenerateWdgIf_B ####################################################################
    moduleName = 'WdgIf'
    Bswmd_WdgIf = os.path.join('bswmd', 'Bswmd_WdgIf.arxml')

    Bswmd_WdgIf = env.GenerateBSW(
        target=Bswmd_WdgIf,
        source=[
            Ecud_WdgIf, Ecud_Wdg, Bswmd_Wdg_43,
        ],
        BSW_GENERATOR=WdgIf,
        BSWDEFINES='B',
    )
    Alias('Generate' + moduleName + '_B', Bswmd_WdgIf)
    ##################################################################################

    # GenerateWdgM_B ####################################################################
    moduleName = 'WdgM'
    Bswmd_WdgM = os.path.join('bswmd', 'Bswmd_WdgM.arxml')

    Bswmd_WdgM = env.GenerateBSW(
        target=Bswmd_WdgM,
        source=[
            Ecud_WdgM, Ecud_WdgIf, Ecud_Dem, Ecud_Os, Ecud_EcuC, Ecud_Mcu
        ],
        BSW_GENERATOR=WdgM,
        BSWDEFINES='B',
    )
    Alias('Generate' + moduleName + '_B', Bswmd_WdgM)
    ##################################################################################

    ## GenerateEcuM_B ####################################################################
    moduleName = 'EcuM'
    Bswmd_EcuM = os.path.join('bswmd', 'Bswmd_EcuM.arxml')

    Bswmd_EcuM = env.GenerateBSW(
        target=Bswmd_EcuM,
        source=[
            Ecud_EcuM,
        ],
        BSW_GENERATOR=EcuM,
        BSWDEFINES='B',
    )
    Alias('Generate' + moduleName + '_B', Bswmd_EcuM)
    ###################################################################################

    # GenerateCal_B ##################################################################
    #moduleName = 'Cal'
    #Bswmd_Cal = os.path.join('bswmd', 'Bswmd_Cal.arxml')

    #Bswmd_Cal = env.GenerateBSW(
    #   target=Bswmd_Cal,
    #    source=[
    #        Ecud_Cal, Ecud_HwResource
    #    ],
    #    BSW_GENERATOR=Cal,
    #    BSWDEFINES='B',
    #)
    #Alias('Generate' + moduleName + '_B', Bswmd_Cal)
    ##################################################################################

    # GenerateCal ####################################################################
    #moduleName = 'Cal'
    #generateBSW = env.GenerateBSW(
    #    target=['inc' + os.sep + moduleName + '_Cfg.h', 'src' + os.sep + moduleName + '_Cfg.c'],
    #    source=[
    #        Bswmd_Cal, Ecud_Cal, Ecud_HwResource
    #    ],
    #    BSW_GENERATOR=Cal,
    #)
    #generated += [generateBSW]
    #env.Depends(generateBSW, Bswmd_Cal)
    #Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateCanIf ####################################################################
    moduleName = 'CanIf'
    expectedFiles = [
        os.path.join('inc', moduleName + '_Can.h'),
        os.path.join('inc', moduleName + '_Cbk.h'),
        os.path.join('inc', moduleName + '_Cfg.h'),
        os.path.join('inc', moduleName + '_UserInc.h'),
        os.path.join('src', moduleName + '_Cfg.c'),
    ]
    generateBSW = env.GenerateBSW(
        target=expectedFiles,
        source=[
            Bswmd_CanIf, Bswmd_Can,
            Ecud_CanIf, Ecud_EcuC, Ecud_CanTp, Ecud_PduR,
            Ecud_Can,
        ],
        BSW_GENERATOR=CanIf,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateCanSM ####################################################################
    moduleName = 'CanSM'
    generateBSW = env.GenerateBSW(
        target=[
            'inc' + os.sep + moduleName + '_Cfg.h',
            'src' + os.sep + moduleName + '_Cfg.c'],
        source=[Bswmd_CanSM, Bswmd_CanIf, Bswmd_ComM,
                Ecud_CanSM, Ecud_ComM, Ecud_CanIf, Ecud_Dem,
        ],
        BSW_GENERATOR=CanSM,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateCanTp ####################################################################
    moduleName = 'CanTp'
    generateBSW = env.GenerateBSW(
        target=[
            'inc' + os.sep + moduleName + '_Cfg.h',
            'src' + os.sep + moduleName + '_Cfg.c'],
        source=[Bswmd_CanTp,
                Ecud_CanTp, Ecud_PduR, Ecud_CanIf, ],
        BSW_GENERATOR=CanTp,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateCom ####################################################################
    moduleName = 'Com'
    expectedFiles = [
        os.path.join('inc', moduleName + '_Cbk.h'),
        os.path.join('inc', moduleName + '_Cfg.h'),
        os.path.join('src', moduleName + '_Cfg.c'),
    ]
    defines = [
        'Bend',
    ]
    generateBSW = env.GenerateBSW(
        target=expectedFiles,
        source=[Bswmd_Com, Bswmd_CanIf, Bswmd_PduR,
                Ecud_Com, Ecud_PduR, Ecud_EcuC],
        BSW_GENERATOR=Com,
        BSWDEFINES=defines,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateComM ####################################################################
    moduleName = 'ComM'
    generateBSW = env.GenerateBSW(
        target=['inc' + os.sep + moduleName + '_Cfg.h', 'src' + os.sep + moduleName + '_Cfg.c'],
        source=[
            Bswmd_ComM,
            Ecud_ComM,
        ],
        BSW_GENERATOR=ComM,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateCrc ####################################################################
    moduleName = 'Crc'
    generateBSW = env.GenerateBSW(
        target=['inc' + os.sep + moduleName + '_Cfg.h'],
        source=[Bswmd_Crc, Ecud_Crc, ],
        BSW_GENERATOR=Crc,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateDcm ####################################################################
    moduleName = 'Dcm'
    generateBSW = env.GenerateBSW(
        target=[
            'inc' + os.sep + moduleName + '_Cfg.h',
            'inc' + os.sep + moduleName + '_Routine.h',
            'src' + os.sep + moduleName + '_Cfg.c',
            'src' + os.sep + moduleName + '_Routine.c',
        ],
        source=[Bswmd_Dcm, Ecud_Dcm, Ecud_PduR, Ecud_NvM, Ecud_ComM, Ecud_EcuC],
        BSW_GENERATOR=Dcm,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateDem ####################################################################
    moduleName = 'Dem'
    generateBSW = env.GenerateBSW(
        target=['inc' + os.sep + moduleName + '_Cfg.h', 'src' + os.sep + moduleName + '_Cfg.c'],
        source=[Bswmd_Dem, Ecud_Dem, Ecud_Dcm, Ecud_NvM, ],
        BSW_GENERATOR=Dem,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateDet ####################################################################
    moduleName = 'Det'
    expectedFiles = [
        os.path.join('inc', moduleName + '_Cfg.h'),
        os.path.join('src', moduleName + '_Cfg.c'),
    ]
    generateBSW = env.GenerateBSW(
        target=expectedFiles,
        source=[Bswmd_Det, Ecud_Det, Ecud_EcuC, ],
        BSW_GENERATOR=Det,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateFiM ####################################################################
    moduleName = 'FiM'
    generateBSW = env.GenerateBSW(
        target=[
            'inc' + os.sep + moduleName + '_Cfg.h',
            'src' + os.sep + moduleName + '_Cfg.c',
        ],
        source=[Bswmd_FiM,
                Ecud_FiM, Ecud_Dem,
        ],
        BSW_GENERATOR=FiM,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateIoHwAb ####################################################################
    moduleName = 'IoHwAb'
    expectedFiles = [
        os.path.join('inc', moduleName + '_Cfg.h'),
        os.path.join('src', moduleName + '_Cfg.c'),
    ]
    generateBSW = env.GenerateBSW(
        target=expectedFiles,
        source=[
            Ecud_IoHwAb, Ecud_Os,
            Ecud_Port, Ecud_Dio, Ecud_Adc, Ecud_Mcu, Ecud_Pwm, Ecud_Icu, Ecud_Spi, Ecud_Gpt,
            Bswmd_IoHwAb, Bswmd_Icu_43, Bswmd_Pwm_43,
            ],
        BSW_GENERATOR=IoHwAb,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateMemIf ####################################################################
    moduleName = 'MemIf'
    expectedFiles = [
        os.path.join('inc', moduleName + '_Cfg.h'),
        os.path.join('inc', moduleName + '.h'),
        os.path.join('src', moduleName + '.c'),
    ]
    generateBSW = env.GenerateBSW(
        target=expectedFiles,
        source=[
            Bswmd_Fee, Bswmd_Fls, Bswmd_MemIf,
            Ecud_MemIf, Ecud_NvM,
            Ecud_Fee, Ecud_Fls,
        ],
        BSW_GENERATOR=MemIf,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateNvM ####################################################################
    moduleName = 'NvM'
    expectedFiles = [
        os.path.join('inc', moduleName + '_Cfg.h'),
        # os.path.join('inc', moduleName+'_Dem_Cfg.h'),
        os.path.join('src', moduleName + '_Cfg.c'),
    ]
    generateBSW = env.GenerateBSW(
        target=expectedFiles,
        source=[
            Bswmd_NvM,
            Ecud_NvM, Ecud_Dem, Ecud_Gpt,
            Ecud_Fee, Ecud_Fls,
        ],
        BSW_GENERATOR=NvM,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GeneratePduR ####################################################################
    moduleName = 'PduR'
    expectedFiles = [
        os.path.join('inc', moduleName + '_CanIf.h'),
        os.path.join('inc', moduleName + '_Cfg.h'),
        os.path.join('inc', moduleName + '_Com.h'),
        os.path.join('inc', moduleName + '_Incl.h'),
        os.path.join('inc', moduleName + '_CanTp.h'),
        os.path.join('inc', moduleName + '_Dcm.h'),
        os.path.join('src', moduleName + '_CallBk.c'),
        os.path.join('src', moduleName + '_Cfg.c'),
    ]
    generateBSW = env.GenerateBSW(
        target=expectedFiles,
        source=[Bswmd_PduR, Bswmd_Com, Bswmd_CanIf, Bswmd_CanTp, Bswmd_Dcm,
                Ecud_PduR, Ecud_EcuC, Ecud_Com, Ecud_CanIf,
                Ecud_Dcm, Ecud_CanTp,
        ],
        BSW_GENERATOR=PduR,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateWdgIf ####################################################################
    moduleName = 'WdgIf'
    expectedFiles = [
        os.path.join('inc', moduleName + '_Cfg.h'),
        os.path.join('inc', moduleName + '_Types.h'),
        os.path.join('inc', moduleName + '_Version.h'),
        os.path.join('inc', moduleName + '.h'),
        os.path.join('src', moduleName + '_Version.c'),
        os.path.join('src', moduleName + '.c'),
    ]
    generateBSW = env.GenerateBSW(
        target=expectedFiles,
        source=[
            Ecud_WdgIf, Ecud_Wdg, Bswmd_WdgIf, Bswmd_Wdg_43,
        ],
        BSW_GENERATOR=WdgIf,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateWdgM ####################################################################
    moduleName = 'WdgM'
    expectedFiles = [
        os.path.join('inc', moduleName + '_Cfg.h'),
        os.path.join('inc', moduleName + '_Dem_Cfg.h'),
        os.path.join('inc', moduleName + '_GenExterns.h'),
        os.path.join('src', moduleName + '_Cfg.c'),
    ]
    generateBSW = env.GenerateBSW(
        target=expectedFiles,
        source=[
            Ecud_WdgM, Ecud_WdgIf, Ecud_Dem, Ecud_Os, Ecud_EcuC, Ecud_Mcu, Bswmd_WdgM
        ],
        BSW_GENERATOR=WdgM,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateOsProfiler #############################################################
    moduleName = 'Opf'
    generateBSW = env.GenerateBSW(
        target=[
            os.path.join('inc', moduleName + '_Cfg.h'),
            os.path.join('src', moduleName + '_Cfg.c'),
        ],
        source=[
            Ecud_OsProfiler, Ecud_Os,
            Bswmd_OsProfiler,
        ],
        BSW_GENERATOR=OsProfiler,
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateIoHwAb_S ####################################################################
    moduleName = 'IoHwAb'
    Swcd_IoHwAb = os.path.join('swcd', 'Swcd_IoHwAb.arxml')

    Swcd_IoHwAb = env.GenerateBSW(
        target=Swcd_IoHwAb,
        source=[
            Ecud_IoHwAb, Ecud_Os, Ecud_Pwm, Ecud_Icu, Ecud_Spi, Ecud_Gpt,
            Ecud_Port, Ecud_Dio, Ecud_Adc, Ecud_Mcu,
            Bswmd_IoHwAb, Bswmd_Icu_43, Bswmd_Pwm_43,
        ],
        BSW_GENERATOR=IoHwAb,
        BSWDEFINES='S',
    )
    env.Depends(generateBSW, Bswmd_IoHwAb)
    Alias('Generate' + moduleName + '_S', Swcd_IoHwAb)
    ##################################################################################

    # GenerateWdgM_S ####################################################################
    moduleName = 'WdgM'
    Swcd_WdgM = os.path.join('swcd', 'Swcd_WdgM.arxml')

    Swcd_WdgM = env.GenerateBSW(
        target=Swcd_WdgM,
        source=[
            Ecud_WdgM, Ecud_WdgIf, Ecud_Dem, Ecud_Os, Ecud_EcuC, Ecud_Mcu,
            Bswmd_WdgM
        ],
        BSW_GENERATOR=WdgM,
        BSWDEFINES='S',
    )
    env.Depends(generateBSW, Bswmd_WdgM)
    Alias('Generate' + moduleName + '_S', Swcd_WdgM)
    ##################################################################################

    ## GenerateEcuM_S ####################################################################
    moduleName = 'EcuM'
    Swcd_Bsw_EcuM = os.path.join('swcd', 'Swcd_Bsw_EcuM.arxml')

    Swcd_Bsw_EcuM = env.GenerateBSW(
        target=Swcd_Bsw_EcuM,
        source=[
            Ecud_EcuM,
        ],
        BSW_GENERATOR=EcuM,
        BSWDEFINES='S',
    )
    env.Depends(generateBSW, Bswmd_EcuM)
    Alias('Generate' + moduleName + '_S', Swcd_Bsw_EcuM)
    ###################################################################################

    # GenerateNvM_S #############################################################
    moduleName = 'NvM'
    Swcd_Bsw_NvM = os.path.join('swcd', 'Swcd_Bsw_NvM.arxml')

    Swcd_Bsw_NvM = env.GenerateBSW(
        target=Swcd_Bsw_NvM,
        source=[
            Ecud_NvM, Ecud_Fee, Ecud_Dem, Bswmd_NvM,
        ],
        BSW_GENERATOR=NvM,
        BSWDEFINES=['S', 'P']
    )
    Alias('Generate' + moduleName + '_S', Swcd_Bsw_NvM)
    ################################################################################

   # GenerateDcm_S #############################################################
    moduleName = 'Dcm'
    Swcd_Bsw_Dcm = os.path.join('swcd', 'Swcd_Bsw_Dcm.arxml')

    Swcd_Bsw_Dcm = env.GenerateBSW(
        target=Swcd_Bsw_Dcm,
        source=[Bswmd_Dcm, Ecud_Dcm, Ecud_PduR, Ecud_NvM, Ecud_ComM, Ecud_EcuC],
        BSW_GENERATOR=Dcm,
        BSWDEFINES='S',
    )
    Alias('Generate' + moduleName + '_S', Swcd_Bsw_Dcm)
    ################################################################################

   # GenerateDem_S #############################################################
    moduleName = 'Dem'
    Swcd_Bsw_Dem = os.path.join('swcd', 'Swcd_Bsw_Dem.arxml')

    Swcd_Bsw_Dem = env.GenerateBSW(
        target=Swcd_Bsw_Dem,
        source=[Bswmd_Dem, Ecud_Dem, Ecud_Dcm, Ecud_NvM, ],
        BSW_GENERATOR=Dem,
        BSWDEFINES='S',
    )
    Alias('Generate' + moduleName + '_S', Swcd_Bsw_Dem)
    ################################################################################

    # GenerateBswM ####################################################################
    moduleName = 'BswM'
    expectedFiles = [
        os.path.join('inc', moduleName + '.h'),
        os.path.join('inc', moduleName + '_ActionList.h'),
        os.path.join('inc', moduleName + '_Cfg.h'),
        os.path.join('inc', moduleName + '_PCTypes.h'),
        os.path.join('inc', moduleName + '_Ram.h'),
        os.path.join('inc', moduleName + '_Rule.h'),
        os.path.join('src', moduleName + '.c'),
        os.path.join('src', moduleName + '_ActionList.c'),
        os.path.join('src', moduleName + '_Cfg.c'),
        os.path.join('src', moduleName + '_Ram.c'),
        os.path.join('src', moduleName + '_Rule.c'),
    ]
    generateBSW = env.GenerateBSW(
        target=expectedFiles,
        source=[
            Ecud_BswM, Ecud_Os, Ecud_Com, Ecud_ComM, Ecud_EcuM,Ecud_NvM,
            Bswmd_BswM, Bswmd_Dcm, Bswmd_EcuM, EcuM_PortInterface,
            Swcd_Bsw_BswM, Swcd_Bsw_EcuM, AUTOSAR_DataTypes,
            MODE_PortInterfaces,
        ],
        BSW_GENERATOR=BswM,
        BSWDEFINES=['Warn'],  #suppress warning
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateEcuM ####################################################################
    moduleName = 'EcuM'
    expectedFiles = [
        os.path.join('inc', moduleName + '_Cfg.h'),
        os.path.join('inc', moduleName + '_Generated_Callouts.h'),
        os.path.join('inc', moduleName + '_Generated_Types.h'),
        os.path.join('src', moduleName + '_Cfg.c'),
        os.path.join('src', moduleName + '_Generated_Callouts.c'),
        os.path.join('src', moduleName + '_Lcfg.c'),
        os.path.join('src', moduleName + '_PBcfg.c'),
    ]
    generateBSW = env.GenerateBSW(
        target=expectedFiles,
        source=[
            Ecud_EcuM, Ecud_CanIf, Ecud_CanSM, Ecud_CanTp,
            Ecud_Com, Ecud_ComM, Ecud_Dcm, Ecud_Dem, Ecud_FiM, Ecud_IoHwAb,
            Ecud_Os, Ecud_PduR, Ecud_WdgM, Ecud_Det,
            Ecud_Adc, Ecud_Can, Ecud_Dio, Ecud_Gpt, Ecud_Icu,
            Ecud_Mcu, Ecud_Port, Ecud_Pwm, Ecud_Spi, Ecud_Wdg,
            Bswmd_EcuM, Bswmd_CanIf, Bswmd_CanSM, Bswmd_CanTp,
            Bswmd_Com, Bswmd_ComM, Bswmd_Dcm, Bswmd_Dem, Bswmd_FiM, Bswmd_IoHwAb,
            Bswmd_WdgM, Bswmd_PduR, Bswmd_Spi, Bswmd_Wdg_43, Bswmd_Det,
            Bswmd_Adc, Bswmd_Can, Bswmd_Dio, Bswmd_Gpt, Bswmd_Icu_43,
            Bswmd_Mcu, Bswmd_Port, Bswmd_Pwm_43,
        ],
        BSW_GENERATOR=EcuM,
        BSWDEFINES=[
            'EcuMConfPrefix'
        ]
    )
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)
    ##################################################################################

    # GenerateOs ####################################################################
    moduleName = 'Os'
    expectedFiles = [
        'src' + os.sep + moduleName + '_cfg.c',
        'inc' + os.sep + moduleName + '_cfg.h',
        'inc' + os.sep + moduleName + '_memmap.h',
        'inc' + os.sep + moduleName + '_prop.h',
    ]
    input_link = os.path.join('Build', 'linker_command_file.ld')
    generateBSW = env.GenerateFreescaleOs(
        target=expectedFiles,
        source=Ecud_Os,
        OS_GENERATOR=sg,
        INPUT_LINK=input_link,
        OUTPUTDIRSRC=env['BSW_OUTPUT_DIR'] + os.sep + 'src',
        OUTPUTDIRINC=env['BSW_OUTPUT_DIR'] + os.sep + 'inc',
    )
    env.Requires(generateBSW, generateMCAL)
    generated += [generateBSW]
    Alias('Generate' + moduleName, generateBSW)

    binPath = os.path.dirname(sg)
    autosarXsd = os.path.join(binPath, 'AUTOSAR_4-0-3.xsd')
    autosarXsdOrigin = os.path.join(binPath, 'AUTOSAR_403.xsd')
    freescaleAutosarXsd = os.path.join(binPath, 'FREESCALE_AUTOSAR_4-0.xsd')
    freescaleAutosarXsdOrigin = os.path.join(binPath, 'FREESCALE_AUTOSAR_40.xsd')
    if not os.path.exists(autosarXsd):
        if os.path.exists(autosarXsdOrigin):
            Execute(Copy(autosarXsd, autosarXsdOrigin))
    if not os.path.exists(freescaleAutosarXsd):
        if os.path.exists(freescaleAutosarXsdOrigin):
            Execute(Copy(freescaleAutosarXsd, freescaleAutosarXsdOrigin))
    ##################################################################################

    # GenerateRte ####################################################################
    moduleName = 'Rte'
    expectedFiles = [
        os.path.join('src', 'Rte.c'),
        os.path.join('src', 'Rte_PBCfg.c'),
    ]
    generateBSW = env.GenerateBSW(
        target=expectedFiles,
        source=[
            # Bswmd
            Bswmd_Adc, Bswmd_BswM, Bswmd_CanTp, Bswmd_ComM,
            Bswmd_Can, Bswmd_Dio, Bswmd_Fls, Bswmd_Icu_43, Bswmd_Mcu,
            Bswmd_Port, Bswmd_Spi, Bswmd_Gpt, Bswmd_Pwm_43, Bswmd_Dcm, Bswmd_Dem,
            Bswmd_EcuM, Bswmd_FiM, Bswmd_NvM,
            Bswmd_CanSM, Bswmd_Com, Bswmd_CanIf, Bswmd_PduR, Bswmd_Os,
            Bswmd_IoHwAb, Bswmd_Wdg_43, Bswmd_WdgIf, Bswmd_WdgM,
            Bswmd_Fee, Bswmd_MemIf, Bswmd_Crc, #Bswmd_Cal,
            # Ecud
            Ecud_Rte, Ecud_Os, Ecud_EcuC, Ecud_Com, Bswmd_Det, Ecud_Det,
            #Ecud_Cal,
            # Swcd_Bsw
            Swcd_Bsw_BswM, Swcd_Bsw_Dcm, Swcd_Det, Swcd_ComM,
            Swcd_Bsw_Dem, Swcd_Bsw_EcuM, Swcd_FiM, Swcd_Bsw_NvM,
            Swcd_IoHwAb, Swcd_WdgM, Swcd_WdgM_Fixed,
            # Swcd_App
            App_Dcm, App_Dem, App_FiM, App_ComM,
            App_WdgM, App_ErrM, App_Mode, App_IoHwAb,
            # DB
            Project,
            # Etc
            ECUCD_EcucValueCollection, EcuExtract, AUTOSAR_DataTypes,
            AUTOSAR_DataTypes_Etc, EcuM_PortInterface, MODE_PortInterfaces,

        ],
        BSW_INCLUDE_PATH=[],
        BSW_GENERATOR=Rte,
        BSWDEFINES=[
            'genmemmap',
            'EXCLFUNC',  # TODO : to be continous
            'StrictUnconnRPortChk',
            'CustomPrefix',
            'OsSecPerHwTick=0.000001',
            'Macro',
            'validate',
            #'GenMemMapOption::Ghs',
            'ErrorMsgOnly', #suppress warning
            #'bend',
        ]
    )
    generated += [generateBSW]
    env.Depends(generateBSW, Swcd_Bsw_NvM)
    env.Depends(generateBSW, Swcd_WdgM)
    env.Depends(generateBSW, Swcd_Bsw_Dcm)
    env.Depends(generateBSW, Swcd_Bsw_Dem)
    env.Depends(generateBSW, Swcd_IoHwAb)
    Alias('Generate' + moduleName, generateBSW)
    ###############################################################################

except NameError as error:
    filename = re.match('name \'(\w+)\' is not defined', error.message).group(1)
    message = 'If you intended filename(' + filename + "), the file does not exist.(Case-sensitive)"
    print message
    raise

if env['REMOVE_TIMESTAMP']:
    generated += [env.RemoveTimestamp(generated)]

Alias('Generate', generated)
Alias('GenerateAll', generated)
env.Clean('GenerateAll', [env['BSW_OUTPUT_DIR'], env['MCAL_OUTPUT_DIR']])
Return('generated')
