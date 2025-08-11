
#ifndef MGA_AUTOEVER_SAMPLE_EM_APP2_H_
#define MGA_AUTOEVER_SAMPLE_EM_APP2_H_

#include <ara/log/logging.h>

namespace mga {
namespace autoever {
namespace sample {

class EmApp2 {
public:
    EmApp2(int32_t num);
    ~EmApp2();

    void Init();
    void Act();

private:
    ara::log::Logger& em_app2_logger;
    int32_t app_num;
};

}  // namespace sample
}  // namespace autoever
}  // namespace mga

#endif  // MGA_AUTOEVER_SAMPLE_EM_APP2_H_




