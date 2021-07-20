#include <napi.h>
#include "Wrapper.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	return ClassEx::Init(env, exports);
};

NODE_API_MODULE(exclass, Init);