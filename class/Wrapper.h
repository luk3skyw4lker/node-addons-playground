#include <napi.h>
#include "ExClass.h"

class ClassEx : public Napi::ObjectWrap<ClassEx>
{
public:
	static Napi::Object Init(Napi::Env env, Napi::Object exports);
	ClassEx(const Napi::CallbackInfo &info);

private:
	static Napi::FunctionReference constructor;
	Napi::Value GetValue(const Napi::CallbackInfo &info);
	Napi::Value AddValue(const Napi::CallbackInfo &info);
	ExClass *exClass_;
};