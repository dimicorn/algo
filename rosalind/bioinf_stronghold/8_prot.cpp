#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string s, res = "";
    cin >> s;
    for (int i = 0; i < s.length(); i += 3) {
        if (s[i] == 'U') {
            if (s[i+1] == 'U') {
                if (s[i+2] == 'U' || s[i+2] == 'C') {
                    res += 'F';
                } else if (s[i+2] == 'A' || s[i+2] == 'G') {
                    res += 'L';
                }
            } else if (s[i+1] == 'C') {
                if (s[i+2] == 'U' || s[i+2] == 'C' || s[i+2] == 'A' || s[i+2] == 'G') {
                    res += 'S';
                }
            } else if (s[i+1] == 'A') {
                if (s[i+2] == 'U' || s[i+2] == 'C') {
                    res += 'Y';
                } else if (s[i+2] == 'A' || s[i+2] == 'G') {
                    continue;
                    // res += "Stop";
                }
            } else if (s[i+1] == 'G') {
                if (s[i+2] == 'U' || s[i+2] == 'C') {
                    res += 'C';
                } else if (s[i+2] == 'A') {
                    continue;
                    // res += "Stop";
                } else if (s[i+2] == 'G') {
                    res += 'W';
                }
            }
        } else if (s[i] == 'C') {
            if (s[i+1] == 'U') {
                if (s[i+2] == 'U' || s[i+2] == 'C' || s[i+2] == 'A' || s[i+2] == 'G') {
                    res += 'L';
                }
            } else if (s[i+1] == 'C') {
                if (s[i+2] == 'U' || s[i+2] == 'C' || s[i+2] == 'A' || s[i+2] == 'G') {
                    res += 'P';
                }
            } else if (s[i+1] == 'A') {
                if (s[i+2] == 'U' || s[i+2] == 'C') {
                    res += 'H';
                } else if (s[i+2] == 'A' || s[i+2] == 'G') {
                    res += 'Q';
                }
            } else if (s[i+1] == 'G') {
                if (s[i+2] == 'U' || s[i+2] == 'C' || s[i+2] == 'A' || s[i+2] == 'G') {
                    res += 'R';
                }
            }
        } else if (s[i] == 'A') {
            if (s[i+1] == 'U') {
                if (s[i+2] == 'U' || s[i+2] == 'C' || s[i+2] == 'A') {
                    res += 'I';
                } else if (s[i+2] == 'G') {
                    res += 'M';
                }
            } else if (s[i+1] == 'C') {
                if (s[i+2] == 'U' || s[i+2] == 'C' || s[i+2] == 'A' || s[i+2] == 'G') {
                    res += 'T';
                }
            } else if (s[i+1] == 'A') {
                if (s[i+2] == 'U' || s[i+2] == 'C') {
                    res += 'N';
                } else if (s[i+2] == 'A' || s[i+2] == 'G') {
                    res += 'K';
                }
            } else if (s[i+1] == 'G') {
                if (s[i+2] == 'U' || s[i+2] == 'C') {
                    res += 'S';
                } else if (s[i+2] == 'A' || s[i+2] == 'G') {
                    res += 'R';
                }
            }
        } else if (s[i] == 'G') {
            if (s[i+1] == 'U') {
                if (s[i+2] == 'U' || s[i+2] == 'C' || s[i+2] == 'A' || s[i+2] == 'G') {
                    res += 'V';
                }
            } else if (s[i+1] == 'C') {
                if (s[i+2] == 'U' || s[i+2] == 'C' || s[i+2] == 'A' || s[i+2] == 'G') {
                    res += 'A';
                }
            } else if (s[i+1] == 'A') {
                if (s[i+2] == 'U' || s[i+2] == 'C') {
                    res += 'D';
                } else if (s[i+2] == 'A' || s[i+2] == 'G') {
                    res += 'E';
                }
            } else if (s[i+1] == 'G') {
                if (s[i+2] == 'U' || s[i+2] == 'C' || s[i+2] == 'A' || s[i+2] == 'G') {
                    res += 'G';
                }
            }
        }
    }
    cout << res; 
    return 0;
}

