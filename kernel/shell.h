void aaFunc();
void bbFunc();
void ccFunc();

void parseCommand(char input[]);
void whichWord(char str[]);

void setupShell(void);

typedef char cmdName[16];

struct {
  cmdName names[256];
  void (*funcs[256])();
} commands;