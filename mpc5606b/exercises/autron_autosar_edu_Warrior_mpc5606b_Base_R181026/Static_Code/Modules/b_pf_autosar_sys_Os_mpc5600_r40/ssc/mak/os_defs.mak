#################################################################
#
#  Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc. 
#  All other product or service names are the property of their respective owners. 
#  (C) Freescale Semiconductor, Inc. 2012-2013
# 
#  1. This example is provided "as is", without warranty.
#
#  2. You don't remove this copyright notice from this example or any direct derivation 
#     thereof.
#
#  Description:  AUTOSAR OS defines makefile      
#
#  Notes:        
#
#################################################################

#################################################################
# INTERNAL REQUIRED CONFIGURATION 
# No internal configuration are required
#

#################################################################
# REQUIRED (in base_make)
#
# PROJECT_ROOT - path to the project root given by the project makefile
# SSC_ROOT     - path to the ssc root given by the project makefile
#

#################################################################
# SPECIFIC
#

# Source paths
OS_DIR	       	= $(SSC_ROOT)\$(os_dir)\ssc
_OS_SG_PATH	= bin\generator

OS_SRC_PATH    	= $(OS_DIR)\src
OS_INC_PATH    	= $(OS_DIR)\inc

# SysGen tool path
OS_SG_PATH = $(OS_DIR)\$(_OS_SG_PATH)

#################################################################
# REGISTRY
#
#SSC_PLUGINS += 

# No dependent plugins
#freescale-os_DEPENDENT_PlUGINS =

CC_INCLUDE_PATH += $(OS_INC_PATH)
CPP_INCLUDE_PATH += 
ASM_INCLUDE_PATH +=
