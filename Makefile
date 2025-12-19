# ===定义变量===

TARGET = main
SRC_DIR = source
INC_DIR = include
BUILD_DIR = build

CC = gcc

# ===查找文件===

# 查找所有C文件
SRCS = $(wildcard $(SRC_DIR)/*.c)
# 生成对应的.o文件
OBJS = $(patsubst %.c,  $(BUILD_DIR)/%.o,  $(notdir $(SRCS)))
# 查找所有h文件
DEPS = $(wildcard $(INC_DIR )/*.h)
# 指定头文件路径
CFLAGS = $(patsubst %,  -I%,  $(INC_DIR))

# ===目标===

$(BUILD_DIR)/$(TARGET) : $(OBJS)
		$(CC) -o $@ $^ $(CFLAGS)

# ===编译规则===

# 编译c文件为.o文件
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c $(DEPS)
# 创建编译目录
	@mkdir -p $(BUILD_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)
#	echo"构建构建目录：$(BUILD_DIR)"

# ==伪目标===

.PHONY : clean cleanall
clean : rm -rf $(BUILD_DIR)
cleanall : rm -rf $(BUILD_DIR)

debug:
	echo"BUILD_DIR: $(BUILD_DIR)"
	echo"TARGET: $(TARGET)"
	echo"OBJS: $(OBJS)"
	echo"SRCS: $(SRCS)"
