cmd_/home/wangyaliang/workspace/tina/out/tulip-d1/compile_dir/toolchain/linux-dev//include/linux/nfsd/.install := bash scripts/headers_install.sh /home/wangyaliang/workspace/tina/out/tulip-d1/compile_dir/toolchain/linux-dev//include/linux/nfsd /home/wangyaliang/workspace/tina/lichee/linux-3.10/include/uapi/linux/nfsd cld.h debug.h export.h nfsfh.h stats.h; bash scripts/headers_install.sh /home/wangyaliang/workspace/tina/out/tulip-d1/compile_dir/toolchain/linux-dev//include/linux/nfsd /home/wangyaliang/workspace/tina/lichee/linux-3.10/include/linux/nfsd ; bash scripts/headers_install.sh /home/wangyaliang/workspace/tina/out/tulip-d1/compile_dir/toolchain/linux-dev//include/linux/nfsd /home/wangyaliang/workspace/tina/lichee/linux-3.10/include/generated/uapi/linux/nfsd ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/wangyaliang/workspace/tina/out/tulip-d1/compile_dir/toolchain/linux-dev//include/linux/nfsd/$$F; done; touch /home/wangyaliang/workspace/tina/out/tulip-d1/compile_dir/toolchain/linux-dev//include/linux/nfsd/.install