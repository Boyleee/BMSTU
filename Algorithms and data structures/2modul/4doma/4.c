void shellsort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j))
{
    for (int d = nel/2; d > 0; d /= 2) {
        for (int k = 1; k < nel; k += d) {
            int loc = k - 1;
            while (loc > -1 && (compare(loc, loc + d) > 0)) {
                swap(loc, loc + d);
                loc -= d;
            }
        }
    }
}