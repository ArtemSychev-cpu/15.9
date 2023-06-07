#pragma once
#include <string>


constexpr auto LOGINLENGTH = 20;
constexpr auto HASHCOEFMULTI = 0.6180339887;
typedef char LoginName[LOGINLENGTH]; //Òèï èìÿ ëîãèíà

class Chat 
{
public:
  Chat();
  ~Chat(); 
 
  void reg(LoginName login, std::string const password);
  void del(LoginName login);
  auto find(LoginName login)->std::string const;
  void resize();
  void delDeleted();
  auto get_memsize() const->size_t;
  auto get_array_login(size_t i) const->LoginName&;

private:
  
  enum enPairStatus { free, engaged, deleted };
  struct AuthData 
  {
    
    AuthData();

    
    AuthData(LoginName login, std::string const password);
    auto operator = (const AuthData& other)->AuthData&;
    ~AuthData() {};

    LoginName _login{};
    std::string _password;
    enPairStatus _status;
  };
  auto hash_func(LoginName login, size_t offset) -> size_t;

  AuthData* _array{};
  size_t _mem_size = 0;
  size_t _count = 0;
  size_t _delCount = 0;
};
