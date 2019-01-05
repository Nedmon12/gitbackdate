

bool cmdOptionExists(char** begin, char** end, const std::string& option) {
  return std::find(begin, end, option) != end;
}

char* getCmdOption(char **begin, char ** end, const std::string & option) {
  char ** itr = std::find(begin,end,option);
  if (itr != end && ++itr != end) {
    return *itr;
  }
  return 0;
}


//gitbackD options
//
int main (int argc, char * argv[]) {
  //IDK what I am doing
  std::cout<<"Not ready yet obv"<<std::endl;
  return 0;
}
