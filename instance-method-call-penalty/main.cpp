#include "a.hpp"


A a;
A *a_ptr(&a);
A &a_ref(a);

int main()
{
#if defined(STATIC)
	return A::getOneStatic();
#elif defined(INSTANCE)
	return a.getOne();
#elif defined(INSTANCE_PTR)
	return a_ptr->getOne();
#elif defined(INSTANCE_REF)
	return a_ref.getOne();
#endif
}
