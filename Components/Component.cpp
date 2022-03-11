#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
	IsSelected = false;
}
void Component::setName(string n)
{
	m_Label = n;
}
string Component::getName()
{
	return m_Label;
}
void Component::setSelected()
{
	IsSelected = !IsSelected;
}

GraphicsInfo Component::GetGraphicsInfo()
{
	return m_GfxInfo;
}

CompType Component::GetCompType()
{
	return m_CompType;
}

Component::Component()
{}

Component::~Component()
{}

