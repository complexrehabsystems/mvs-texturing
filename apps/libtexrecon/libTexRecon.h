#include <string>

std::vector<std::string> split(const std::string& str, const std::string& delim)
{
  std::vector<std::string> tokens;
  size_t prev = 0, pos = 0;
  do
  {
    pos = str.find(delim, prev);
    if (pos == std::string::npos) pos = str.length();
    std::string token = str.substr(prev, pos - prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
  } while (pos < str.length() && prev < str.length());
  return tokens;
}

int runTexReconInternal( int argc , char* argv[] );
int runTexRecon(const std::string cmd) {
  auto tokens = split(cmd, " ");
  char** cargs = new char*[tokens.size()];

  auto i = 0;
  for (auto& t : tokens)
  {
    char* writable = new char[t.size() + 1];
    std::copy(t.begin(), t.end(), writable);
    writable[t.size()] = '\0'; // don't forget the terminating 0

    std::cout << "argv[" << i << "]: " << writable << std::endl;
    cargs[i] = writable;
    // don't forget to free the string after finished using it
    i++;

    // NOTE: need to delete writables somewhere...
  }

  auto result = runTexReconInternal(tokens.size(), cargs);

  for(int i=0; i<tokens.size(); i++) {
    delete[] cargs[i];
  }

  delete [] cargs;

  return result;

}

