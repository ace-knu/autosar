
#ifndef MGA_AUTOEVER_SAMPLE_EM_APP1_H_
#define MGA_AUTOEVER_SAMPLE_EM_APP1_H_

#include <ara/log/logging.h>

namespace mga {
namespace autoever {
namespace sample {

class EmApp1 {
public:
    EmApp1();
    ~EmApp1();

    void Init();
    void Act();

private:
    ara::log::Logger& em_app1_logger;
};

}  // namespace sample
}  // namespace autoever
}  // namespace mga

#endif  // MGA_AUTOEVER_SAMPLE_EM_APP1_H_


