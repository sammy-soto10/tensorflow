/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "tensorflow/lite/delegates/gpu/cl/kernels/cl_test.h"
#include "tensorflow/lite/delegates/gpu/common/operations.h"
#include "tensorflow/lite/delegates/gpu/common/status.h"
#include "tensorflow/lite/delegates/gpu/common/tasks/space_to_depth_test_util.h"

namespace tflite {
namespace gpu {
namespace cl {
namespace {

// A known Qualcomm Adreno bug makes the 1 channel test fail on some Adreno
// 5xxs.
TEST_F(OpenCLOperationTest, SpaceToDepthTensorShape1x2x2x1BlockSize2) {
  auto status = SpaceToDepthTensorShape1x2x2x1BlockSize2Test(&exec_env_);
  ASSERT_TRUE(status.ok()) << status.error_message();
}

TEST_F(OpenCLOperationTest, SpaceToDepthTensorShape1x2x2x2BlockSize2) {
  auto status = SpaceToDepthTensorShape1x2x2x2BlockSize2Test(&exec_env_);
  ASSERT_TRUE(status.ok()) << status.error_message();
}

TEST_F(OpenCLOperationTest, SpaceToDepthTensorShape1x2x2x3BlockSize2) {
  auto status = SpaceToDepthTensorShape1x2x2x3BlockSize2Test(&exec_env_);
  ASSERT_TRUE(status.ok()) << status.error_message();
}

TEST_F(OpenCLOperationTest, SpaceToDepthTensorShape1x4x4x1BlockSize2) {
  auto status = SpaceToDepthTensorShape1x4x4x1BlockSize2Test(&exec_env_);
  ASSERT_TRUE(status.ok()) << status.error_message();
}

}  // namespace
}  // namespace cl
}  // namespace gpu
}  // namespace tflite
