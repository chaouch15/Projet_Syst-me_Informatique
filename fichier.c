int f(int b){
return b + 2;
}
int g(int b){
  int c = f(2);
return b + 2;
}

void main() {
  int a = g(2);
}