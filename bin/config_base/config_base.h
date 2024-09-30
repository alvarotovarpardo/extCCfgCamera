#ifndef CCONFIG_BASE_H_
#define CCONFIG_BASE_H_

#define CFGCLASS_MAX_NAME 20


class CCfgClass
{
public:
    CCfgClass(const char *szName);
    virtual ~CCfgClass();

    virtual void initDefault() = 0;
    virtual void display() = 0;
    virtual void matchField(std::string &sAtributo, Jzon::Node &nodoValor) = 0;
    virtual void serializeFields(Jzon::Node &node) = 0;

    char *getName() { return m_szName; }
    void setName(const char *szName) { strncpy_s(m_szName, szName, CFGCLASS_MAX_NAME); }

protected:
    void fillFinalClass(Jzon::Node &nodeGen, CCfgClass *cfgClass);
    char m_szName[CFGCLASS_MAX_NAME+1];

};


#endif /* CCONFIG_BASE_H_ */