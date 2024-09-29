
int add(int a, int b)
{
    if(a == 0 || b == 0)
    return a | b;

    return add(a ^ b, (a & b) << 1);
}