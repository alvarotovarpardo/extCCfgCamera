#include "config_base.h"

CCfgClass::CCfgClass(const char *szName)
{
    strncpy_s(m_szName, szName, CFGCLASS_MAX_NAME);
}

CCfgClass::~CCfgClass()
{

}