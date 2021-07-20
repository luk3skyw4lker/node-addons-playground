#include "Wrapper.h"

Napi::FunctionReference ClassEx::constructor;

Napi::Object ClassEx::Init(Napi::Env env, Napi::Object exports)
{
	Napi::HandleScope scope(env);

	Napi::Function func = DefineClass(env, "ClassEx", {
		InstanceMethod("add", &ClassEx::AddValue),
		InstanceMethod("getValue", &ClassEx::GetValue),
	});

	constructor = Napi::Persistent(func);
	constructor.SuppressDestruct();

	exports.Set("ClassEx", func);

	return exports;
};

ClassEx::ClassEx(const Napi::CallbackInfo& info) : Napi::ObjectWrap<ClassEx>(info) {
	Napi::Env env = info.Env();
	Napi::HandleScope scope(env);

	int length = info.Length();

	if(length != 1 || !info[0].IsNumber()) {
		Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
	}

	Napi::Number value = info[0].As<Napi::Number>();

	this->exClass_ = new ExClass(value.DoubleValue());
};

Napi::Value ClassEx::GetValue(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::HandleScope scope(env);

	double num = this->exClass_->getValue();

	return Napi::Number::New(env, num);
};

Napi::Value ClassEx::AddValue(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::HandleScope scope(env);

	if(info.Length() != 1 || !info[0].IsNumber()) {
		Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
	}

	Napi::Number toAdd = info[0].As<Napi::Number>();

	double answer = this->exClass_->addValue(toAdd.DoubleValue());

	return Napi::Number::New(env, answer);
};