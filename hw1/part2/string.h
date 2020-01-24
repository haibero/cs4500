class String: public Object {
  public:
    const char* val_;
    size_t len_;

    String(){
      val_ = "";
      len_ = 0;
    }

    String(const char* val) {
      val_ = val;
      len_ = strlen(val);
    }

    ~String() {
      delete [] val_;
     }

     size_t hash() {
       if (hash_ == 0) hash_ = hash_me();
       return hash_;
     }

     size_t hash_me() {
       size_t hashNum = 0;
       for(size_t i = 0; i < len_; i++){
         hashNum += size_t(val_[i]);
       }
       return hashNum;
     }


     bool equals(Object* o) {
       if(o == nullptr) {
         return false;
       }
       String* temp = dynamic_cast<String*> (o);
       if(o == nullptr) {
         return false;
       }
       return hash_ == temp -> hash_;
     }

    char get(size_t i) {
      assert(i < len_);
      return val_[i];
    }

    String* concat(String* val) {
      size_t newLen = len_ + val -> len_;
      char* newString = new char[newLen];
      for(size_t i = 0; i < len_; i++){
        newString[i] = val_[i];
      }
      for(size_t j = 0; j < val->len_; j++) {
        newString[j + len_] = val -> val_[j];
      }
      return new String(newString);
    }
};
