#include <iostream>
#include <stdint.h>


class
StaticBase
{
public:
	enum class
	TestEnum
	{
		A,
		B,
	};
};

template<int I>
class
TemplateBase : public StaticBase
{
protected:
	static TestEnum
	value;
public:
	static void
	setEnum(TestEnum v)
	{
		value = v;
		int c = I;
	}
};

template<int I>
typename TemplateBase<I>::TestEnum
TemplateBase<I>::value =
TemplateBase<I>::TestEnum::A;

class
NotATemplateBase : public StaticBase
{
protected:
	static TestEnum
	value;
public:
	static void
	setEnum(TestEnum v)
	{
		value = v;
	}
};

NotATemplateBase::TestEnum
NotATemplateBase::value =
NotATemplateBase::TestEnum::A;


template<int I>
class
TemplateClass : public TemplateBase<I>//NotATemplateBase
{
public:
	static void
	setEnum(typename TemplateBase<I>::TestEnum v)
	{
		TemplateBase<I>::value = v;
		int c = I;
	}
};

int main()
{
	std::cout << "nothing to see here ...."<< std::endl;
}
