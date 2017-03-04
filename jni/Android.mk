LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CPP_EXTENSION := .cpp .cc

LOCAL_SRC_FILES = main.cpp interpreter/Interpreter.cpp utils/StringUtils.cpp interpreter/Parameter.cpp

LOCAL_MODULE := interpreterCpp

include $(BUILD_EXECUTABLE)
