# Tina_R16
## 1.配置环境
`source build/envsetup.sh`
## 2.加载板子配置
`lunch astar_parrot-tina`
## 3.编译
`make -j1`
## 4.打包
`pack -d`

# 添加交叉编译环境


# 编译u-boot
## 1.进入u-boot目录
`cd lichee/brandy/u-boot-2011.09`
## 2.加载配置文件
`make sun8iw5p1_config`
## 3.编译
`make -j1`
编译会提醒找不到 -lssl 和-lcrypto，问题在交叉编译器缺少动态连接库ssl.so和crypto.so。
