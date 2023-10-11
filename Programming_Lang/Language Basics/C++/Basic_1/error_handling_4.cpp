/*
Invariants:
Statement which is assumed to be true for a class is called class invariants or invariant.
Job of constructor to establish the invariant for its class.
*/

int main()
{
    static_assert(10 >= sizeof(int),"size of int too big");
    // static_assert(<condiction>,<statement to print if condiction is false>)
}