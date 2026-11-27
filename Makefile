# ===定义变量===

TARGET = main
SRC_DIR = source
INC_DIR = include
BUILD_DIR = build

CC = gcc
# -std=gnu11 是为了 getline 等 POSIX 接口
CFLAGS = -O2 -std=gnu11 -I$(INC_DIR)

# ===查找文件===

# 查找所有C文件
SRCS = $(wildcard $(SRC_DIR)/*.c)
# 生成对应的.o文件
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
# 查找所有h文件
DEPS = $(wildcard $(INC_DIR)/*.h)

# ===目标===

all : $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

# ===编译规则===

# 编译c文件为.o文件
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c $(DEPS)
	@mkdir -p $(BUILD_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

# ==伪目标===

.PHONY : all clean cleanall debug

clean :
	rm -rf $(BUILD_DIR)

cleanall : clean

debug :
	@echo "BUILD_DIR: $(BUILD_DIR)"
	@echo "TARGET: $(TARGET)"
	@echo "OBJS: $(OBJS)"
	@echo "SRCS: $(SRCS)"
