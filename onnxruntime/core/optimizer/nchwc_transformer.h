// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "core/common/common.h"
#include "core/optimizer/graph_transformer.h"

namespace onnxruntime {

/**
@Class NchwcTransformer

Transformer that optimizes the graph by using NCHWc nodes instead of NCHW nodes
and inserts nodes to reorder tensors as needed.
*/
class NchwcTransformer : public GraphTransformer {
 public:
  explicit NchwcTransformer(const InlinedHashSet<std::string_view>& compatible_execution_providers) noexcept
      : GraphTransformer("NchwcTransformer", compatible_execution_providers) {}

 private:
  Status ApplyImpl(Graph& graph, bool& modified, int graph_level, const logging::Logger& logger) const override;
};

}  // namespace onnxruntime
