
int switch_prob(int x, int n){
    int result = x;

    switch(n){
        case 40,42:
            result = x << 3;
            break;
        case 43:
            result = x >> 3;
            break;
        case 44:
            result = x << 3 - x;
        case 45:
            result = x * x + 0x11;
            break;
        default:
            result = x + 0x11;
            break;
    }

    return result;
}
