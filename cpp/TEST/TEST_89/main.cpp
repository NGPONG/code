#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <unordered_set>
#include <variant>
#include <type_traits>
#include <map>
#include <set>
#include <unordered_set>
#include <random>
#include <chrono>
#include <algorithm>
#include <bit>
#include <bitset>
#include <array>
#include <utility>
#include <list>
#include <functional>
#include <sstream>

class KWMail;
class KWMailBuilder;
class KWMailHeaderBuilder;
class KWMailBodyBuilder;

class KWMail {
public:
    std::string mail_id;
    std::string context;
    std::string sender;
};

class KWMailBuilder {
protected:
    KWMail mMail;

public:
    virtual ~KWMailBuilder() { }

public:
    operator KWMail() const;

    KWMailHeaderBuilder& Header() const;
    KWMailBodyBuilder& Body() const;
};

class KWMailHeaderBuilder : public KWMailBuilder {
public:
    KWMailHeaderBuilder &set_sender(const std::string& sender) { mMail.sender = sender; return *this; };
};

class KWMailBodyBuilder : public KWMailBuilder {
public:
    KWMailBodyBuilder &set_mailid(const std::string& mailid) { mMail.mail_id = mailid; return *this; };
    KWMailBodyBuilder &set_context(const std::string& context) { mMail.context = context; return *this; };
};

KWMailBuilder::operator KWMail() const {
    return std::move(mMail);
};

KWMailHeaderBuilder& KWMailBuilder::Header() const {
    std::cout << 1 << std::endl;
    
    return dynamic_cast<KWMailHeaderBuilder&>(*const_cast<KWMailBuilder*>(this));
}

KWMailBodyBuilder& KWMailBuilder::Body() const {
    return dynamic_cast<KWMailBodyBuilder&>(*const_cast<KWMailBuilder*>(this));
}

KWMailBuilder foo() {
    return KWMailBuilder();
}

int32_t main(void) {
    foo().Header();

    return 0;
}
