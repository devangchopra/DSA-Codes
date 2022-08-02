// Complex Number Multiplication


string complexNumberMultiply(string num1, string num2) {
  int a1, a2 , b1 , b2;

  int pos1 = num1.find('+');

  string real1 = num1.substr(0, pos1);
  string img1 = num1.substr(pos1 + 1, num1.length() - 1);
  
  a1 = stoi(real1);
  b1 = stoi(img1);

  int pos2 = num2.find('+');

  string real2 = num2.substr(0, pos2);
  string img2 = num2.substr(pos2 + 1, num2.length() - 1);

  
  a2 = stoi(real2);
  b2 = stoi(img2);

  int realPart = ((a1 * a2) -  (b1 * b2)) ;
  int imaginaryPart = ((a1 * b2) + (a2 * b1));

  string ans;
  ans = to_string (realPart) + '+' + to_string(imaginaryPart) + 'i';

  return ans;
}