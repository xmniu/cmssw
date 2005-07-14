#ifndef EVENTSETUP_DATAKEYTAGS_H
#define EVENTSETUP_DATAKEYTAGS_H
// -*- C++ -*-
//
// Package:     Framework
// Class  :     DataKeyTags
// 
/**\class DataKeyTags DataKeyTags.h FWCore/Framework/interface/DataKeyTags.h

 Description: <one line class summary>

 Usage:
    <usage>

*/
//
// Author:      Chris Jones
// Created:     Thu Mar 31 14:13:07 EST 2005
// $Id: DataKeyTags.h,v 1.2 2005/06/23 19:59:30 wmtan Exp $
//

// system include files

// user include files
#include "FWCore/Framework/interface/HCTypeTag.h"

// forward declarations
namespace edm {
   namespace eventsetup {
      
      class DataKey;
      
      typedef heterocontainer::HCTypeTag<DataKey> TypeTag;
      
      class SimpleStringTag {
        public:
         SimpleStringTag(const char* iString) : tag_(iString) {}
         SimpleStringTag() : tag_("") {}
         bool operator==(const SimpleStringTag& iRHS) const ;
         bool operator<(const SimpleStringTag& iRHS) const ;
         
         const char* value() const { return tag_; }
         
        private:
         const char* tag_;
      };

      class NameTag : public SimpleStringTag {
       public:
         NameTag(const char* iUsage) : SimpleStringTag(iUsage) {}
         NameTag() : SimpleStringTag() {}
      };
      
      typedef NameTag IdTags;
   }
}
#endif /* EVENTSETUP_DATAKEYTAGS_H */
