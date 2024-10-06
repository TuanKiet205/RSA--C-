#include <stdio.h>
#include <stdlib.h>
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return result;
}
// vd chon p va q la mot so nguyen bat ky (..)
void generate_keys(int *e, int *d, int *n) {
    int p = 61, q = 53;
    *n = p * q; 
    int phi = (p - 1) * (q - 1);
    *e = 17;  // nguyen to cung nhau voi n
    for (*d = 2; (*d * *e) % phi != 2; (*d)++);   // tinh nghich dao cua e trong phep modun
}

long long encrypt(int e, int n, long long msg) {
    return mod_exp(msg, e, n);
}

long long decrypt(int d, int n, long long cipher) {
    return mod_exp(cipher, d, n);
}

int main() {
    int e, d, n;
    generate_keys(&e, &d, &n);

    printf("Khoa cong khai: (e: %d, n: %d)\n", e, n);
    printf("Khoa bi mat: (d: %d)\n", d);
    long long msg;
    printf("nhap du lieu (so nguyen nho hon n): ");
    scanf("%lld", &msg);
    long long cipher = encrypt(e, n, msg);
    printf("du lieu da ma hoa: %lld\n", cipher);
    long long decrypted_msg = decrypt(d, n, cipher);
    printf("du lieu sau khi giai ma: %lld\n", decrypted_msg);

    return 0;
}


