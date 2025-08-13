out.exe : 2025_07_25.c 
# out.exe : 2025_07_25.c  //依赖关系 最终生成可执行文件依赖 2025_07_25.c 
# out.exe 最终生成可执行文件 
	g++   2025_07_25.c   add.c    -o out.exe
# 	编译文件 添加编译需要的依赖文件 add.c   || -o 重命名文件

clean :
	rm -f out.exe
# 	删除生成的可执行文件

.PHONY : out.exe clean
#  每次生成文件的时候都必须从新编译