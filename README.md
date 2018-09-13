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
