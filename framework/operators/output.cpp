#include "framework/operators/output.h"

namespace anakin {

namespace ops {

template<>
void Output<NV, AK_FLOAT, Precision::FP32>::operator()(
    OpContext<NV>& ctx,
    const std::vector<Tensor4dPtr<NV, AK_FLOAT>>& ins,
    std::vector<Tensor4dPtr<NV, AK_FLOAT>>& outs) {
}


/// TODO ... specialization other type of operator


/// set helper
template<typename Ttype, DataType Dtype, Precision Ptype>
OutputHelper<Ttype, Dtype, Ptype>::~OutputHelper() {
}

template<typename Ttype, DataType Dtype, Precision Ptype>
Status OutputHelper<Ttype, Dtype, Ptype>::InitParam() {
    return Status::OK();
}

template<typename Ttype, DataType Dtype, Precision Ptype>
Status OutputHelper<Ttype, Dtype, Ptype>::Init(OpContext<Ttype>& ctx,
        const std::vector<Tensor4dPtr<Ttype, Dtype>>& ins,
        std::vector<Tensor4dPtr<Ttype, Dtype>>& outs) {
}

template<typename Ttype, DataType Dtype, Precision Ptype>
Status OutputHelper<Ttype, Dtype, Ptype>::InferShape(const std::vector<Tensor4dPtr<Ttype, Dtype> >&
        ins,
        std::vector<Tensor4dPtr<Ttype, Dtype> >& outs) {
    return Status::OK();
}

template class OutputHelper<NV, AK_FLOAT, Precision::FP32>;
template class OutputHelper<NV, AK_FLOAT, Precision::FP16>;
template class OutputHelper<NV, AK_FLOAT, Precision::INT8>;

template class OutputHelper<ARM, AK_FLOAT, Precision::FP32>;
template class OutputHelper<ARM, AK_FLOAT, Precision::FP16>;
template class OutputHelper<ARM, AK_FLOAT, Precision::INT8>;

// register help
ANAKIN_REGISTER_OP_HELPER(Output, OutputHelper, NV, AK_FLOAT, Precision::FP32);
ANAKIN_REGISTER_OP_HELPER(Output, OutputHelper, NV, AK_FLOAT, Precision::FP16);
ANAKIN_REGISTER_OP_HELPER(Output, OutputHelper, NV, AK_FLOAT, Precision::INT8);

ANAKIN_REGISTER_OP_HELPER(Output, OutputHelper, ARM, AK_FLOAT, Precision::FP32);
ANAKIN_REGISTER_OP_HELPER(Output, OutputHelper, ARM, AK_FLOAT, Precision::FP16);
ANAKIN_REGISTER_OP_HELPER(Output, OutputHelper, ARM, AK_FLOAT, Precision::INT8);

//! register op
ANAKIN_REGISTER_OP(Output)
.Doc("Output operator [ only a input data holder and reshape ] ")
.__alias__<NV, AK_FLOAT, Precision::FP32>("output")
.__alias__<ARM, AK_FLOAT, Precision::FP32>("output");

} /* namespace ops */

} /* namespace anakin */


