COMPONENT_NAME=assert

SRC_FILES = \

MOCK_AND_FAKE_SRC_FILES += \

TEST_SRC_FILES = \
  $(MFLT_TEST_SRC_DIR)/test_assert.cpp \
  $(MOCK_AND_FAKE_SRC_FILES)

# Blank out noreturn for this test
CPPUTEST_CPPFLAGS += -DMEMFAULT_NORETURN=""

include $(CPPUTEST_MAKFILE_INFRA)
