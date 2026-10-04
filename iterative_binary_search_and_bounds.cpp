int binary_search(int v, int a[], int l, int r) {
    while (l <= r) {
        int m = l + (r-l)/2;
        if (v > a[m]) {
            l = m + 1;
        } else if (v < a[m]) {
            r = m - 1;
        } else {
            return m;
        }
  }
  return -1;
}

int lower_bound(int v, int a[], int l, int r) {
    while (l < r) {
        int m = l + (r-l)/2;
        if (v > a[m]) {
            l = m + 1;
        } else {
            r = m;
        }
  }
  return l;
}

int upper_bound_(int v, int a[], int l, int r) { 
    while (l < r) {
        int m = l + (r - l) / 2;
        if (v >= a[m]) l = m + 1;
        else r = m;
    }
    return l; 
}
