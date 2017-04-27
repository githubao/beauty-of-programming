// Created by BaoQiang at 2017/4/27 21:10

/*
 * 烙饼的翻转排序
 * */

#include <stdio.h>
#include <assert.h>


class CPrefixSorting {
public:
    CPrefixSorting() {
        m_nCakeCnt = 0;
        m_nMaxSwap = 0;
    }

    ~CPrefixSorting() {
        if (m_CakeArray != NULL) {
            delete m_CakeArray;
        }
        if (m_SwapArray != NULL) {
            delete m_SwapArray;
        }
        if (m_ReverseCakeArray != NULL) {
            delete m_ReverseCakeArray;
        }
        if (m_ReverseCakeArraySwap != NULL) {
            delete m_ReverseCakeArraySwap;
        }
    }

    void Run(int *pCakeArray, int nCakeCnt) {
        Init(pCakeArray, nCakeCnt);
        m_nSearch = 0;
        Search(0);
    }

    void Output() {
        printf("\nReversed every cnt: ");
        for (int i = 0; i < m_nMaxSwap; ++i) {
            printf("%d ", m_SwapArray[i]);
        }
        printf("\n |Search Times| : %d\n", m_nSearch);
        printf("Total Swap Times = %d\n", m_nMaxSwap);
    }

private:
    void Init(int *pCakeArray, int nCakeCnt) {
        assert(pCakeArray != NULL);
        assert(nCakeCnt > 0);

        m_nCakeCnt = nCakeCnt;

//        初始化烙饼数组
        m_CakeArray = new int[m_nCakeCnt];
        assert(m_CakeArray != NULL);
        for (int i = 0; i < m_nCakeCnt; ++i) {
            m_CakeArray[i] = pCakeArray[i];
        }

//      最多交换次数
        m_nMaxSwap = UpperBound(m_nCakeCnt);

//        交换结果数组
        m_SwapArray = new int[m_nMaxSwap + 1];
        assert(m_SwapArray != NULL);

//        中间交换结果信息
        m_ReverseCakeArray = new int[m_nCakeCnt];
        for (int i = 0; i < m_nCakeCnt; ++i) {
            m_ReverseCakeArray[i] = m_CakeArray[i];
        }

        m_ReverseCakeArraySwap = new int[m_nMaxSwap];
    }

    int UpperBound(int nCakeCnt) {
        return 2 * nCakeCnt;
    }

    int LowerBound(int *pCakeArray, int nCakeCnt) {
        int t, ret = 0;
        for (int i = 1; i < nCakeCnt; ++i) {
            t = pCakeArray[i] - pCakeArray[i - 1];
            if ((t == 1) || (t == -1)) {

            } else {
                ret++;
            }
        }
        return ret;
    }

    void Search(int step) {
        int i, nEstimate;
        m_nSearch++;

        nEstimate = LowerBound(m_ReverseCakeArray, m_nCakeCnt);
        if (step + nEstimate > m_nMaxSwap) {
            return;
        }

        if (IsSorted(m_ReverseCakeArray, m_nCakeCnt)) {
            if (step < m_nMaxSwap) {
                m_nMaxSwap = step;
                for (i = 0; i < m_nMaxSwap; ++i) {
                    m_SwapArray[i] = m_ReverseCakeArraySwap[i];
                }
            }
            return;
        }

        for (i = 1; i < m_nCakeCnt; ++i) {
            Reverse(0, i);
            m_ReverseCakeArraySwap[step] = i;
            Search(step + 1);
            Reverse(0, i);
        }
    }

    bool IsSorted(int *pCakeArray, int nCakeCnt) {
        for (int i = 1; i < nCakeCnt; ++i) {
            if (pCakeArray[i - 1] > pCakeArray[i]) {
                return false;
            }
        }
        return true;
    }

    void Reverse(int nBegin, int nEnd) {
        assert(nEnd > nBegin);
        int i, j, t;

        for (i = nBegin, j = nEnd; i < j; i++, j--) {
            t = m_ReverseCakeArray[i];
            m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
            m_ReverseCakeArray[j] = t;
        }
    }


private:
    int *m_CakeArray;
    int m_nCakeCnt;
    int m_nMaxSwap;

    int *m_SwapArray;
    int *m_ReverseCakeArray;
    int *m_ReverseCakeArraySwap;
    int m_nSearch;

};


int main() {
    CPrefixSorting *cPrefixSorting = new CPrefixSorting();
    int a[10] = {3, 2, 1, 6, 5, 4, 9, 8, 7, 0};
//    int a[2] = {1, 0};

    cPrefixSorting->Run(a, sizeof(a) / sizeof(int));
    cPrefixSorting->Output();

    delete cPrefixSorting;
}

int main2() {
    printf("Reversed cake: ");
}