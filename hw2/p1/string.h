// lang :: CwC

/**
  * ClassName - purpose and interpretation
  *
  * @author Barry Yung <yung.b@northeastern.edu>
  */

class String: public Object {
  public:
    const char* val_; //Characters of the string
    size_t len_; //Length of the string

    String(){
      val_ = "";
      len_ = 0;
      hash_ = hash();
    }

    String(const char* val) {
      val_ = val;
      len_ = strlen(val);
      hash_ = hash();
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
       if(temp == nullptr) {
         return false;
       }
       return strcmp(val_, temp -> val_) == 0;
     }

     int cmp(String* const s) {
       return strcmp(val_, s -> val_);
     }

    char get(size_t i) {
      if(i < len_){
      return val_[i];
      }
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

    size_t size() {
      return len_;
    }
};
