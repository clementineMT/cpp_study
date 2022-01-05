#ifndef __B_HPP__
#define __B_HPP__
class B
{
public:
	B()
	{
 
	}
	void setCallBack(void (*callback)(int,int));
};
 
void B::setCallBack(void (*callback)(int,int))
{
	callback(1, 2);
}
 
#endif