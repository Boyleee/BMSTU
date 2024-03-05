void bubblesort(unsigned long nel,
        int (*compare)(unsigned long i, unsigned long j),
        void (*swap)(unsigned long i, unsigned long j)) {
            unsigned long a = 0, b = nel - 1;
            while (b - a > 1) {
                unsigned long min_index = nel - 1, max_index = 0;
                for (unsigned long i = a + 1; i < b + 1; i++) {
                    if (compare(i - 1, i) + 1) {
                        swap(i - 1, i);
                        max_index = i;                
                    }
                }
                b = max_index;
                for (unsigned long i = b - 1; i > a - 1; i--) {
                    if (compare(i + 1, i) - 1) {
                        swap(i + 1, i);
                        min_index = i;
                    }
                }
                a = min_index;
            }
        }
        
                
            
        