//AUTOGENERATED BY genLayout.py
  
#ifndef __DOMAIN_LAYOUT_H__
#define __DOMAIN_LAYOUT_H__



    struct PERM_I {};
    struct PERM_IJ {};
    struct PERM_JI {};
    struct PERM_IJK {};
    struct PERM_IKJ {};
    struct PERM_JIK {};
    struct PERM_JKI {};
    struct PERM_KIJ {};
    struct PERM_KJI {};
    struct PERM_IJKL {};
    struct PERM_IJLK {};
    struct PERM_IKJL {};
    struct PERM_IKLJ {};
    struct PERM_ILJK {};
    struct PERM_ILKJ {};
    struct PERM_JIKL {};
    struct PERM_JILK {};
    struct PERM_JKIL {};
    struct PERM_JKLI {};
    struct PERM_JLIK {};
    struct PERM_JLKI {};
    struct PERM_KIJL {};
    struct PERM_KILJ {};
    struct PERM_KJIL {};
    struct PERM_KJLI {};
    struct PERM_KLIJ {};
    struct PERM_KLJI {};
    struct PERM_LIJK {};
    struct PERM_LIKJ {};
    struct PERM_LJIK {};
    struct PERM_LJKI {};
    struct PERM_LKIJ {};
    struct PERM_LKJI {};

    template<typename L>
    struct Layout1d {
        inline explicit Layout1d(int ni);
        inline int operator()(int i) const;
        inline void toIndices(int linear, int &i) const;

        int const size_i;

        int const stride_i;
    };

    template<typename L>
    struct Layout2d {
        inline Layout2d(int ni, int nj);
        inline int operator()(int i, int j) const;
        inline void toIndices(int linear, int &i, int &j) const;

        int const size_i;
        int const size_j;

        int const stride_i;
        int const stride_j;
    };

    template<typename L>
    struct Layout3d {
        inline Layout3d(int ni, int nj, int nk);
        inline int operator()(int i, int j, int k) const;
        inline void toIndices(int linear, int &i, int &j, int &k) const;

        int const size_i;
        int const size_j;
        int const size_k;

        int const stride_i;
        int const stride_j;
        int const stride_k;
    };

    template<typename L>
    struct Layout4d {
        inline Layout4d(int ni, int nj, int nk, int nl);
        inline int operator()(int i, int j, int k, int l) const;
        inline void toIndices(int linear, int &i, int &j, int &k, int &l) const;

        int const size_i;
        int const size_j;
        int const size_k;
        int const size_l;

        int const stride_i;
        int const stride_j;
        int const stride_k;
        int const stride_l;
    };


/******************************************************************
 *  Implementation for Layout1D
 ******************************************************************/

      template<>
      inline Layout1d<PERM_I>::Layout1d(int ni):
        size_i(ni), stride_i(1)
      {
      }

      template<>
      inline int Layout1d<PERM_I>::operator()(int i) const {
        return(i);
      }

      template<>
      inline void Layout1d<PERM_I>::toIndices(int linear, int &i) const {
        i = linear;
      }


/******************************************************************
 *  Implementation for Layout2D
 ******************************************************************/

      template<>
      inline Layout2d<PERM_IJ>::Layout2d(int ni, int nj):
        size_i(ni), size_j(nj), stride_i(nj), stride_j(1)
      {
      }

      template<>
      inline int Layout2d<PERM_IJ>::operator()(int i, int j) const {
        return(i*stride_i + j);
      }

      template<>
      inline void Layout2d<PERM_IJ>::toIndices(int linear, int &i, int &j) const {
        i = linear / (size_j);
        linear -= i*(size_j);
        j = linear;
      }

      template<>
      inline Layout2d<PERM_JI>::Layout2d(int ni, int nj):
        size_i(ni), size_j(nj), stride_j(ni), stride_i(1)
      {
      }

      template<>
      inline int Layout2d<PERM_JI>::operator()(int i, int j) const {
        return(j*stride_j + i);
      }

      template<>
      inline void Layout2d<PERM_JI>::toIndices(int linear, int &i, int &j) const {
        j = linear / (size_i);
        linear -= j*(size_i);
        i = linear;
      }


/******************************************************************
 *  Implementation for Layout3D
 ******************************************************************/

      template<>
      inline Layout3d<PERM_IJK>::Layout3d(int ni, int nj, int nk):
        size_i(ni), size_j(nj), size_k(nk), stride_i(nj*nk), stride_j(nk), stride_k(1)
      {
      }

      template<>
      inline int Layout3d<PERM_IJK>::operator()(int i, int j, int k) const {
        return(i*stride_i + j*stride_j + k);
      }

      template<>
      inline void Layout3d<PERM_IJK>::toIndices(int linear, int &i, int &j, int &k) const {
        i = linear / (size_j*size_k);
        linear -= i*(size_j*size_k);
        j = linear / (size_k);
        linear -= j*(size_k);
        k = linear;
      }

      template<>
      inline Layout3d<PERM_IKJ>::Layout3d(int ni, int nj, int nk):
        size_i(ni), size_j(nj), size_k(nk), stride_i(nk*nj), stride_k(nj), stride_j(1)
      {
      }

      template<>
      inline int Layout3d<PERM_IKJ>::operator()(int i, int j, int k) const {
        return(i*stride_i + k*stride_k + j);
      }

      template<>
      inline void Layout3d<PERM_IKJ>::toIndices(int linear, int &i, int &j, int &k) const {
        i = linear / (size_k*size_j);
        linear -= i*(size_k*size_j);
        k = linear / (size_j);
        linear -= k*(size_j);
        j = linear;
      }

      template<>
      inline Layout3d<PERM_JIK>::Layout3d(int ni, int nj, int nk):
        size_i(ni), size_j(nj), size_k(nk), stride_j(ni*nk), stride_i(nk), stride_k(1)
      {
      }

      template<>
      inline int Layout3d<PERM_JIK>::operator()(int i, int j, int k) const {
        return(j*stride_j + i*stride_i + k);
      }

      template<>
      inline void Layout3d<PERM_JIK>::toIndices(int linear, int &i, int &j, int &k) const {
        j = linear / (size_i*size_k);
        linear -= j*(size_i*size_k);
        i = linear / (size_k);
        linear -= i*(size_k);
        k = linear;
      }

      template<>
      inline Layout3d<PERM_JKI>::Layout3d(int ni, int nj, int nk):
        size_i(ni), size_j(nj), size_k(nk), stride_j(nk*ni), stride_k(ni), stride_i(1)
      {
      }

      template<>
      inline int Layout3d<PERM_JKI>::operator()(int i, int j, int k) const {
        return(j*stride_j + k*stride_k + i);
      }

      template<>
      inline void Layout3d<PERM_JKI>::toIndices(int linear, int &i, int &j, int &k) const {
        j = linear / (size_k*size_i);
        linear -= j*(size_k*size_i);
        k = linear / (size_i);
        linear -= k*(size_i);
        i = linear;
      }

      template<>
      inline Layout3d<PERM_KIJ>::Layout3d(int ni, int nj, int nk):
        size_i(ni), size_j(nj), size_k(nk), stride_k(ni*nj), stride_i(nj), stride_j(1)
      {
      }

      template<>
      inline int Layout3d<PERM_KIJ>::operator()(int i, int j, int k) const {
        return(k*stride_k + i*stride_i + j);
      }

      template<>
      inline void Layout3d<PERM_KIJ>::toIndices(int linear, int &i, int &j, int &k) const {
        k = linear / (size_i*size_j);
        linear -= k*(size_i*size_j);
        i = linear / (size_j);
        linear -= i*(size_j);
        j = linear;
      }

      template<>
      inline Layout3d<PERM_KJI>::Layout3d(int ni, int nj, int nk):
        size_i(ni), size_j(nj), size_k(nk), stride_k(nj*ni), stride_j(ni), stride_i(1)
      {
      }

      template<>
      inline int Layout3d<PERM_KJI>::operator()(int i, int j, int k) const {
        return(k*stride_k + j*stride_j + i);
      }

      template<>
      inline void Layout3d<PERM_KJI>::toIndices(int linear, int &i, int &j, int &k) const {
        k = linear / (size_j*size_i);
        linear -= k*(size_j*size_i);
        j = linear / (size_i);
        linear -= j*(size_i);
        i = linear;
      }


/******************************************************************
 *  Implementation for Layout4D
 ******************************************************************/

      template<>
      inline Layout4d<PERM_IJKL>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_i(nj*nk*nl), stride_j(nk*nl), stride_k(nl), stride_l(1)
      {
      }

      template<>
      inline int Layout4d<PERM_IJKL>::operator()(int i, int j, int k, int l) const {
        return(i*stride_i + j*stride_j + k*stride_k + l);
      }

      template<>
      inline void Layout4d<PERM_IJKL>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        i = linear / (size_j*size_k*size_l);
        linear -= i*(size_j*size_k*size_l);
        j = linear / (size_k*size_l);
        linear -= j*(size_k*size_l);
        k = linear / (size_l);
        linear -= k*(size_l);
        l = linear;
      }

      template<>
      inline Layout4d<PERM_IJLK>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_i(nj*nl*nk), stride_j(nl*nk), stride_l(nk), stride_k(1)
      {
      }

      template<>
      inline int Layout4d<PERM_IJLK>::operator()(int i, int j, int k, int l) const {
        return(i*stride_i + j*stride_j + l*stride_l + k);
      }

      template<>
      inline void Layout4d<PERM_IJLK>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        i = linear / (size_j*size_l*size_k);
        linear -= i*(size_j*size_l*size_k);
        j = linear / (size_l*size_k);
        linear -= j*(size_l*size_k);
        l = linear / (size_k);
        linear -= l*(size_k);
        k = linear;
      }

      template<>
      inline Layout4d<PERM_IKJL>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_i(nk*nj*nl), stride_k(nj*nl), stride_j(nl), stride_l(1)
      {
      }

      template<>
      inline int Layout4d<PERM_IKJL>::operator()(int i, int j, int k, int l) const {
        return(i*stride_i + k*stride_k + j*stride_j + l);
      }

      template<>
      inline void Layout4d<PERM_IKJL>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        i = linear / (size_k*size_j*size_l);
        linear -= i*(size_k*size_j*size_l);
        k = linear / (size_j*size_l);
        linear -= k*(size_j*size_l);
        j = linear / (size_l);
        linear -= j*(size_l);
        l = linear;
      }

      template<>
      inline Layout4d<PERM_IKLJ>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_i(nk*nl*nj), stride_k(nl*nj), stride_l(nj), stride_j(1)
      {
      }

      template<>
      inline int Layout4d<PERM_IKLJ>::operator()(int i, int j, int k, int l) const {
        return(i*stride_i + k*stride_k + l*stride_l + j);
      }

      template<>
      inline void Layout4d<PERM_IKLJ>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        i = linear / (size_k*size_l*size_j);
        linear -= i*(size_k*size_l*size_j);
        k = linear / (size_l*size_j);
        linear -= k*(size_l*size_j);
        l = linear / (size_j);
        linear -= l*(size_j);
        j = linear;
      }

      template<>
      inline Layout4d<PERM_ILJK>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_i(nl*nj*nk), stride_l(nj*nk), stride_j(nk), stride_k(1)
      {
      }

      template<>
      inline int Layout4d<PERM_ILJK>::operator()(int i, int j, int k, int l) const {
        return(i*stride_i + l*stride_l + j*stride_j + k);
      }

      template<>
      inline void Layout4d<PERM_ILJK>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        i = linear / (size_l*size_j*size_k);
        linear -= i*(size_l*size_j*size_k);
        l = linear / (size_j*size_k);
        linear -= l*(size_j*size_k);
        j = linear / (size_k);
        linear -= j*(size_k);
        k = linear;
      }

      template<>
      inline Layout4d<PERM_ILKJ>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_i(nl*nk*nj), stride_l(nk*nj), stride_k(nj), stride_j(1)
      {
      }

      template<>
      inline int Layout4d<PERM_ILKJ>::operator()(int i, int j, int k, int l) const {
        return(i*stride_i + l*stride_l + k*stride_k + j);
      }

      template<>
      inline void Layout4d<PERM_ILKJ>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        i = linear / (size_l*size_k*size_j);
        linear -= i*(size_l*size_k*size_j);
        l = linear / (size_k*size_j);
        linear -= l*(size_k*size_j);
        k = linear / (size_j);
        linear -= k*(size_j);
        j = linear;
      }

      template<>
      inline Layout4d<PERM_JIKL>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_j(ni*nk*nl), stride_i(nk*nl), stride_k(nl), stride_l(1)
      {
      }

      template<>
      inline int Layout4d<PERM_JIKL>::operator()(int i, int j, int k, int l) const {
        return(j*stride_j + i*stride_i + k*stride_k + l);
      }

      template<>
      inline void Layout4d<PERM_JIKL>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        j = linear / (size_i*size_k*size_l);
        linear -= j*(size_i*size_k*size_l);
        i = linear / (size_k*size_l);
        linear -= i*(size_k*size_l);
        k = linear / (size_l);
        linear -= k*(size_l);
        l = linear;
      }

      template<>
      inline Layout4d<PERM_JILK>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_j(ni*nl*nk), stride_i(nl*nk), stride_l(nk), stride_k(1)
      {
      }

      template<>
      inline int Layout4d<PERM_JILK>::operator()(int i, int j, int k, int l) const {
        return(j*stride_j + i*stride_i + l*stride_l + k);
      }

      template<>
      inline void Layout4d<PERM_JILK>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        j = linear / (size_i*size_l*size_k);
        linear -= j*(size_i*size_l*size_k);
        i = linear / (size_l*size_k);
        linear -= i*(size_l*size_k);
        l = linear / (size_k);
        linear -= l*(size_k);
        k = linear;
      }

      template<>
      inline Layout4d<PERM_JKIL>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_j(nk*ni*nl), stride_k(ni*nl), stride_i(nl), stride_l(1)
      {
      }

      template<>
      inline int Layout4d<PERM_JKIL>::operator()(int i, int j, int k, int l) const {
        return(j*stride_j + k*stride_k + i*stride_i + l);
      }

      template<>
      inline void Layout4d<PERM_JKIL>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        j = linear / (size_k*size_i*size_l);
        linear -= j*(size_k*size_i*size_l);
        k = linear / (size_i*size_l);
        linear -= k*(size_i*size_l);
        i = linear / (size_l);
        linear -= i*(size_l);
        l = linear;
      }

      template<>
      inline Layout4d<PERM_JKLI>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_j(nk*nl*ni), stride_k(nl*ni), stride_l(ni), stride_i(1)
      {
      }

      template<>
      inline int Layout4d<PERM_JKLI>::operator()(int i, int j, int k, int l) const {
        return(j*stride_j + k*stride_k + l*stride_l + i);
      }

      template<>
      inline void Layout4d<PERM_JKLI>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        j = linear / (size_k*size_l*size_i);
        linear -= j*(size_k*size_l*size_i);
        k = linear / (size_l*size_i);
        linear -= k*(size_l*size_i);
        l = linear / (size_i);
        linear -= l*(size_i);
        i = linear;
      }

      template<>
      inline Layout4d<PERM_JLIK>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_j(nl*ni*nk), stride_l(ni*nk), stride_i(nk), stride_k(1)
      {
      }

      template<>
      inline int Layout4d<PERM_JLIK>::operator()(int i, int j, int k, int l) const {
        return(j*stride_j + l*stride_l + i*stride_i + k);
      }

      template<>
      inline void Layout4d<PERM_JLIK>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        j = linear / (size_l*size_i*size_k);
        linear -= j*(size_l*size_i*size_k);
        l = linear / (size_i*size_k);
        linear -= l*(size_i*size_k);
        i = linear / (size_k);
        linear -= i*(size_k);
        k = linear;
      }

      template<>
      inline Layout4d<PERM_JLKI>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_j(nl*nk*ni), stride_l(nk*ni), stride_k(ni), stride_i(1)
      {
      }

      template<>
      inline int Layout4d<PERM_JLKI>::operator()(int i, int j, int k, int l) const {
        return(j*stride_j + l*stride_l + k*stride_k + i);
      }

      template<>
      inline void Layout4d<PERM_JLKI>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        j = linear / (size_l*size_k*size_i);
        linear -= j*(size_l*size_k*size_i);
        l = linear / (size_k*size_i);
        linear -= l*(size_k*size_i);
        k = linear / (size_i);
        linear -= k*(size_i);
        i = linear;
      }

      template<>
      inline Layout4d<PERM_KIJL>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_k(ni*nj*nl), stride_i(nj*nl), stride_j(nl), stride_l(1)
      {
      }

      template<>
      inline int Layout4d<PERM_KIJL>::operator()(int i, int j, int k, int l) const {
        return(k*stride_k + i*stride_i + j*stride_j + l);
      }

      template<>
      inline void Layout4d<PERM_KIJL>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        k = linear / (size_i*size_j*size_l);
        linear -= k*(size_i*size_j*size_l);
        i = linear / (size_j*size_l);
        linear -= i*(size_j*size_l);
        j = linear / (size_l);
        linear -= j*(size_l);
        l = linear;
      }

      template<>
      inline Layout4d<PERM_KILJ>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_k(ni*nl*nj), stride_i(nl*nj), stride_l(nj), stride_j(1)
      {
      }

      template<>
      inline int Layout4d<PERM_KILJ>::operator()(int i, int j, int k, int l) const {
        return(k*stride_k + i*stride_i + l*stride_l + j);
      }

      template<>
      inline void Layout4d<PERM_KILJ>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        k = linear / (size_i*size_l*size_j);
        linear -= k*(size_i*size_l*size_j);
        i = linear / (size_l*size_j);
        linear -= i*(size_l*size_j);
        l = linear / (size_j);
        linear -= l*(size_j);
        j = linear;
      }

      template<>
      inline Layout4d<PERM_KJIL>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_k(nj*ni*nl), stride_j(ni*nl), stride_i(nl), stride_l(1)
      {
      }

      template<>
      inline int Layout4d<PERM_KJIL>::operator()(int i, int j, int k, int l) const {
        return(k*stride_k + j*stride_j + i*stride_i + l);
      }

      template<>
      inline void Layout4d<PERM_KJIL>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        k = linear / (size_j*size_i*size_l);
        linear -= k*(size_j*size_i*size_l);
        j = linear / (size_i*size_l);
        linear -= j*(size_i*size_l);
        i = linear / (size_l);
        linear -= i*(size_l);
        l = linear;
      }

      template<>
      inline Layout4d<PERM_KJLI>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_k(nj*nl*ni), stride_j(nl*ni), stride_l(ni), stride_i(1)
      {
      }

      template<>
      inline int Layout4d<PERM_KJLI>::operator()(int i, int j, int k, int l) const {
        return(k*stride_k + j*stride_j + l*stride_l + i);
      }

      template<>
      inline void Layout4d<PERM_KJLI>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        k = linear / (size_j*size_l*size_i);
        linear -= k*(size_j*size_l*size_i);
        j = linear / (size_l*size_i);
        linear -= j*(size_l*size_i);
        l = linear / (size_i);
        linear -= l*(size_i);
        i = linear;
      }

      template<>
      inline Layout4d<PERM_KLIJ>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_k(nl*ni*nj), stride_l(ni*nj), stride_i(nj), stride_j(1)
      {
      }

      template<>
      inline int Layout4d<PERM_KLIJ>::operator()(int i, int j, int k, int l) const {
        return(k*stride_k + l*stride_l + i*stride_i + j);
      }

      template<>
      inline void Layout4d<PERM_KLIJ>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        k = linear / (size_l*size_i*size_j);
        linear -= k*(size_l*size_i*size_j);
        l = linear / (size_i*size_j);
        linear -= l*(size_i*size_j);
        i = linear / (size_j);
        linear -= i*(size_j);
        j = linear;
      }

      template<>
      inline Layout4d<PERM_KLJI>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_k(nl*nj*ni), stride_l(nj*ni), stride_j(ni), stride_i(1)
      {
      }

      template<>
      inline int Layout4d<PERM_KLJI>::operator()(int i, int j, int k, int l) const {
        return(k*stride_k + l*stride_l + j*stride_j + i);
      }

      template<>
      inline void Layout4d<PERM_KLJI>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        k = linear / (size_l*size_j*size_i);
        linear -= k*(size_l*size_j*size_i);
        l = linear / (size_j*size_i);
        linear -= l*(size_j*size_i);
        j = linear / (size_i);
        linear -= j*(size_i);
        i = linear;
      }

      template<>
      inline Layout4d<PERM_LIJK>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_l(ni*nj*nk), stride_i(nj*nk), stride_j(nk), stride_k(1)
      {
      }

      template<>
      inline int Layout4d<PERM_LIJK>::operator()(int i, int j, int k, int l) const {
        return(l*stride_l + i*stride_i + j*stride_j + k);
      }

      template<>
      inline void Layout4d<PERM_LIJK>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        l = linear / (size_i*size_j*size_k);
        linear -= l*(size_i*size_j*size_k);
        i = linear / (size_j*size_k);
        linear -= i*(size_j*size_k);
        j = linear / (size_k);
        linear -= j*(size_k);
        k = linear;
      }

      template<>
      inline Layout4d<PERM_LIKJ>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_l(ni*nk*nj), stride_i(nk*nj), stride_k(nj), stride_j(1)
      {
      }

      template<>
      inline int Layout4d<PERM_LIKJ>::operator()(int i, int j, int k, int l) const {
        return(l*stride_l + i*stride_i + k*stride_k + j);
      }

      template<>
      inline void Layout4d<PERM_LIKJ>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        l = linear / (size_i*size_k*size_j);
        linear -= l*(size_i*size_k*size_j);
        i = linear / (size_k*size_j);
        linear -= i*(size_k*size_j);
        k = linear / (size_j);
        linear -= k*(size_j);
        j = linear;
      }

      template<>
      inline Layout4d<PERM_LJIK>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_l(nj*ni*nk), stride_j(ni*nk), stride_i(nk), stride_k(1)
      {
      }

      template<>
      inline int Layout4d<PERM_LJIK>::operator()(int i, int j, int k, int l) const {
        return(l*stride_l + j*stride_j + i*stride_i + k);
      }

      template<>
      inline void Layout4d<PERM_LJIK>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        l = linear / (size_j*size_i*size_k);
        linear -= l*(size_j*size_i*size_k);
        j = linear / (size_i*size_k);
        linear -= j*(size_i*size_k);
        i = linear / (size_k);
        linear -= i*(size_k);
        k = linear;
      }

      template<>
      inline Layout4d<PERM_LJKI>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_l(nj*nk*ni), stride_j(nk*ni), stride_k(ni), stride_i(1)
      {
      }

      template<>
      inline int Layout4d<PERM_LJKI>::operator()(int i, int j, int k, int l) const {
        return(l*stride_l + j*stride_j + k*stride_k + i);
      }

      template<>
      inline void Layout4d<PERM_LJKI>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        l = linear / (size_j*size_k*size_i);
        linear -= l*(size_j*size_k*size_i);
        j = linear / (size_k*size_i);
        linear -= j*(size_k*size_i);
        k = linear / (size_i);
        linear -= k*(size_i);
        i = linear;
      }

      template<>
      inline Layout4d<PERM_LKIJ>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_l(nk*ni*nj), stride_k(ni*nj), stride_i(nj), stride_j(1)
      {
      }

      template<>
      inline int Layout4d<PERM_LKIJ>::operator()(int i, int j, int k, int l) const {
        return(l*stride_l + k*stride_k + i*stride_i + j);
      }

      template<>
      inline void Layout4d<PERM_LKIJ>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        l = linear / (size_k*size_i*size_j);
        linear -= l*(size_k*size_i*size_j);
        k = linear / (size_i*size_j);
        linear -= k*(size_i*size_j);
        i = linear / (size_j);
        linear -= i*(size_j);
        j = linear;
      }

      template<>
      inline Layout4d<PERM_LKJI>::Layout4d(int ni, int nj, int nk, int nl):
        size_i(ni), size_j(nj), size_k(nk), size_l(nl), stride_l(nk*nj*ni), stride_k(nj*ni), stride_j(ni), stride_i(1)
      {
      }

      template<>
      inline int Layout4d<PERM_LKJI>::operator()(int i, int j, int k, int l) const {
        return(l*stride_l + k*stride_k + j*stride_j + i);
      }

      template<>
      inline void Layout4d<PERM_LKJI>::toIndices(int linear, int &i, int &j, int &k, int &l) const {
        l = linear / (size_k*size_j*size_i);
        linear -= l*(size_k*size_j*size_i);
        k = linear / (size_j*size_i);
        linear -= k*(size_j*size_i);
        j = linear / (size_i);
        linear -= j*(size_i);
        i = linear;
      }


  
#endif

