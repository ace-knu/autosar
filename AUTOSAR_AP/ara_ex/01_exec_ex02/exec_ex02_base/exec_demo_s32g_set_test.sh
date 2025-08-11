#!/bin/sh

#CCU2
BOARD_NAME=${1}
echo input BOARD_NAME is ${BOARD_NAME}

mkdir -p /adar/runtime/tmp/mobilgene

export LD_LIBRARY_PATH=/adar/runtime/lib
echo $LD_LIBRARY_PATH

if [ "${BOARD_NAME}" = "CCU2" ]; then
        rm -f /etc/mobilgene
        ln -sf /adar/runtime/etc/mobilgene /etc/mobilgene
        rm -f /var/lib/mobilgene/vmem
        ln -sf /adar/runtime/tmp/mobilgene /var/lib/mobilgene/vmem
        rm -f /var/lib/mobilgene/nvmem
        ln -sf /adar/runtime/media/mobilgene /var/lib/mobilgene/nvmem
else
        rm -f /etc/mobilgene
        ln -sf /adar/runtime/etc/mobilgene /etc/mobilgene
        rm -f /tmp/mobilgene
        ln -sf /adar/runtime/tmp/mobilgene /tmp/mobilgene
        rm -f /media/mobilgene
        ln -sf /adar/runtime/media/mobilgene /media/mobilgene
fi

#bin/sh
cp -arf /adar/install/bin /adar/runtime/

#etc
cp -arf /adar/install/etc /adar/runtime/

#lib
cp -arf /adar/install/lib /adar/runtime/

#opt
mkdir /adar/runtime/opt
cp -arf /adar/install/opt/mga_dltd /adar/runtime/opt/
cp -arf /adar/install/sampleApp/exec_demo/opt/* /adar/runtime/opt

cp -arf /adar/install/sampleApp/exec_demo/*.sh /adar/runtime
rm -rf /adar/runtime/exec_demo_s32g_set_test.sh

#ara-state-change
cp -arf /adar/install/sampleApp/exec_demo/ara-state-change /adar/runtime
