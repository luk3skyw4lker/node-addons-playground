#include <napi.h>

Napi::Array Method(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();
	uint8_t number[2] = {0, 1};
	Napi::Array arr = Napi::Array::New(env, sizeof(number));

	for (uint8_t i = 0; i < sizeof(number); i++)
	{
		arr.Set(i, number[i]);
	}

	return arr;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
	exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Method));

	return exports;
}

NODE_API_MODULE(hello, Init);