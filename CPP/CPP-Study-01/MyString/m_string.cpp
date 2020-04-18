#include "m_string.h"

#pragma region constructor
/* constructor */
m_string::m_string(const char *data_) {
  if (data_ != nullptr) {
    this->length = strlen(data_);
    this->p_str = new char[this->length + 1];
    strcpy(this->p_str, data_);
  }
}

/* copy constructor */
m_string::m_string(const m_string &str_l) {
  if(str_l.p_str == nullptr) {
    this->length = 0;
    this->p_str = nullptr;
    return;
  }

  dispose();

  this->length = str_l.length;
  this->p_str = new char[str_l.length + 1];
  strcpy(this->p_str, str_l.p_str);
}

/* move constructor */
m_string::m_string(m_string &&str_r) {
  dispose();

  this->length = str_r.length;
  this->p_str = str_r.p_str;

  str_r.length = 0x0;
  str_r.p_str = nullptr;
}

/* destructor */
m_string::~m_string() {
  dispose();
}
#pragma endregion class constructor

#pragma region =
/* copy assignment operator */
m_string &m_string::operator=(const m_string &str_l) {
  dispose();

  this->length = str_l.length;
  this->p_str = new char[str_l.length + 1];
  strcpy(this->p_str, str_l.p_str);

  return *this;
}
/* move assignment operator */
m_string &&m_string::operator=(m_string &&str_r) {
  dispose();

  this->length = str_r.length;
  this->p_str = str_r.p_str;

  str_r.length = 0x0;
  str_r.p_str = nullptr;

  return move(*this);
}
m_string &m_string::operator=(const char *data_) {
  if (data_ != nullptr) {
    int src_length = strlen(data_);

    if (src_length > this->length) {
      dispose();

      this->p_str = new char[src_length + 1];
      strcpy(this->p_str, data_);
    } else {
      memset(this->p_str, 0x0, this->length + 1);
      strcpy(this->p_str, data_);
    }

    this->length = src_length;
  }
  return *this;
}
#pragma endregion class assignment operator constructor

#pragma region[]
char &m_string::operator[](int index) {
  return this->p_str[index];
}
#pragma endregion function

#pragma region +
m_string &m_string::operator+(const char *data_) {
  if (data_ == nullptr || this->p_str == nullptr) {
    return *this;
  }

  char *p_temp = this->p_str;

  this->p_str = new char[this->length + strlen(data_) + 1];
  strcpy(this->p_str, p_temp);
  strcat(this->p_str, data_);

  delete[] p_temp;
  return *this;
}

m_string &m_string::operator+(const m_string &str) {
  if (str.p_str == nullptr) {
    return *this;
  }

  char *p_temp = this->p_str;

  this->p_str = new char[this->length + strlen(str.p_str) + 1];
  strcpy(this->p_str, p_temp);
  strcat(this->p_str, str.p_str);

  delete[] p_temp;
  return *this;
}
#pragma endregion +

#pragma region ==
bool m_string::operator==(const char *str) {
  if (strcmp(this->p_str, str) == 0) {
    return true;
  }
  return false;
}
bool m_string::operator==(const m_string &str) {
  if (strcmp(this->p_str, str.p_str) == 0) {
    return true;
  }
  return false;
}
#pragma endregion ==

#pragma region <<
ostream &operator<<(ostream &cout, const m_string &str) {
  cout << str.p_str;
  return cout;
}
#pragma endregion <<

#pragma region common
void m_string::dispose() {
  if (this->p_str != nullptr) {
    delete[] this->p_str;
    this->p_str = nullptr;
  }
}
#pragma endregion common