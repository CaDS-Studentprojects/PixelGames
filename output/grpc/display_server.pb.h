// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: display_server.proto

#ifndef PROTOBUF_display_5fserver_2eproto__INCLUDED
#define PROTOBUF_display_5fserver_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_display_5fserver_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsDISPLAY_MSGImpl();
void InitDefaultsDISPLAY_MSG();
void InitDefaultsDISPLAY_RESPONSEImpl();
void InitDefaultsDISPLAY_RESPONSE();
inline void InitDefaults() {
  InitDefaultsDISPLAY_MSG();
  InitDefaultsDISPLAY_RESPONSE();
}
}  // namespace protobuf_display_5fserver_2eproto
namespace LED_display {
class DISPLAY_MSG;
class DISPLAY_MSGDefaultTypeInternal;
extern DISPLAY_MSGDefaultTypeInternal _DISPLAY_MSG_default_instance_;
class DISPLAY_RESPONSE;
class DISPLAY_RESPONSEDefaultTypeInternal;
extern DISPLAY_RESPONSEDefaultTypeInternal _DISPLAY_RESPONSE_default_instance_;
}  // namespace LED_display
namespace LED_display {

// ===================================================================

class DISPLAY_MSG : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:LED_display.DISPLAY_MSG) */ {
 public:
  DISPLAY_MSG();
  virtual ~DISPLAY_MSG();

  DISPLAY_MSG(const DISPLAY_MSG& from);

  inline DISPLAY_MSG& operator=(const DISPLAY_MSG& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DISPLAY_MSG(DISPLAY_MSG&& from) noexcept
    : DISPLAY_MSG() {
    *this = ::std::move(from);
  }

  inline DISPLAY_MSG& operator=(DISPLAY_MSG&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const DISPLAY_MSG& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DISPLAY_MSG* internal_default_instance() {
    return reinterpret_cast<const DISPLAY_MSG*>(
               &_DISPLAY_MSG_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(DISPLAY_MSG* other);
  friend void swap(DISPLAY_MSG& a, DISPLAY_MSG& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DISPLAY_MSG* New() const PROTOBUF_FINAL { return New(NULL); }

  DISPLAY_MSG* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const DISPLAY_MSG& from);
  void MergeFrom(const DISPLAY_MSG& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(DISPLAY_MSG* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string pixel_list = 5;
  void clear_pixel_list();
  static const int kPixelListFieldNumber = 5;
  const ::std::string& pixel_list() const;
  void set_pixel_list(const ::std::string& value);
  #if LANG_CXX11
  void set_pixel_list(::std::string&& value);
  #endif
  void set_pixel_list(const char* value);
  void set_pixel_list(const char* value, size_t size);
  ::std::string* mutable_pixel_list();
  ::std::string* release_pixel_list();
  void set_allocated_pixel_list(::std::string* pixel_list);

  // int32 version = 1;
  void clear_version();
  static const int kVersionFieldNumber = 1;
  ::google::protobuf::int32 version() const;
  void set_version(::google::protobuf::int32 value);

  // int32 typ = 2;
  void clear_typ();
  static const int kTypFieldNumber = 2;
  ::google::protobuf::int32 typ() const;
  void set_typ(::google::protobuf::int32 value);

  // int32 dim_x = 3;
  void clear_dim_x();
  static const int kDimXFieldNumber = 3;
  ::google::protobuf::int32 dim_x() const;
  void set_dim_x(::google::protobuf::int32 value);

  // int32 dim_y = 4;
  void clear_dim_y();
  static const int kDimYFieldNumber = 4;
  ::google::protobuf::int32 dim_y() const;
  void set_dim_y(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:LED_display.DISPLAY_MSG)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr pixel_list_;
  ::google::protobuf::int32 version_;
  ::google::protobuf::int32 typ_;
  ::google::protobuf::int32 dim_x_;
  ::google::protobuf::int32 dim_y_;
  mutable int _cached_size_;
  friend struct ::protobuf_display_5fserver_2eproto::TableStruct;
  friend void ::protobuf_display_5fserver_2eproto::InitDefaultsDISPLAY_MSGImpl();
};
// -------------------------------------------------------------------

class DISPLAY_RESPONSE : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:LED_display.DISPLAY_RESPONSE) */ {
 public:
  DISPLAY_RESPONSE();
  virtual ~DISPLAY_RESPONSE();

  DISPLAY_RESPONSE(const DISPLAY_RESPONSE& from);

  inline DISPLAY_RESPONSE& operator=(const DISPLAY_RESPONSE& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DISPLAY_RESPONSE(DISPLAY_RESPONSE&& from) noexcept
    : DISPLAY_RESPONSE() {
    *this = ::std::move(from);
  }

  inline DISPLAY_RESPONSE& operator=(DISPLAY_RESPONSE&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const DISPLAY_RESPONSE& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DISPLAY_RESPONSE* internal_default_instance() {
    return reinterpret_cast<const DISPLAY_RESPONSE*>(
               &_DISPLAY_RESPONSE_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(DISPLAY_RESPONSE* other);
  friend void swap(DISPLAY_RESPONSE& a, DISPLAY_RESPONSE& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DISPLAY_RESPONSE* New() const PROTOBUF_FINAL { return New(NULL); }

  DISPLAY_RESPONSE* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const DISPLAY_RESPONSE& from);
  void MergeFrom(const DISPLAY_RESPONSE& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(DISPLAY_RESPONSE* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bool success = 1;
  void clear_success();
  static const int kSuccessFieldNumber = 1;
  bool success() const;
  void set_success(bool value);

  // @@protoc_insertion_point(class_scope:LED_display.DISPLAY_RESPONSE)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool success_;
  mutable int _cached_size_;
  friend struct ::protobuf_display_5fserver_2eproto::TableStruct;
  friend void ::protobuf_display_5fserver_2eproto::InitDefaultsDISPLAY_RESPONSEImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// DISPLAY_MSG

// int32 version = 1;
inline void DISPLAY_MSG::clear_version() {
  version_ = 0;
}
inline ::google::protobuf::int32 DISPLAY_MSG::version() const {
  // @@protoc_insertion_point(field_get:LED_display.DISPLAY_MSG.version)
  return version_;
}
inline void DISPLAY_MSG::set_version(::google::protobuf::int32 value) {
  
  version_ = value;
  // @@protoc_insertion_point(field_set:LED_display.DISPLAY_MSG.version)
}

// int32 typ = 2;
inline void DISPLAY_MSG::clear_typ() {
  typ_ = 0;
}
inline ::google::protobuf::int32 DISPLAY_MSG::typ() const {
  // @@protoc_insertion_point(field_get:LED_display.DISPLAY_MSG.typ)
  return typ_;
}
inline void DISPLAY_MSG::set_typ(::google::protobuf::int32 value) {
  
  typ_ = value;
  // @@protoc_insertion_point(field_set:LED_display.DISPLAY_MSG.typ)
}

// int32 dim_x = 3;
inline void DISPLAY_MSG::clear_dim_x() {
  dim_x_ = 0;
}
inline ::google::protobuf::int32 DISPLAY_MSG::dim_x() const {
  // @@protoc_insertion_point(field_get:LED_display.DISPLAY_MSG.dim_x)
  return dim_x_;
}
inline void DISPLAY_MSG::set_dim_x(::google::protobuf::int32 value) {
  
  dim_x_ = value;
  // @@protoc_insertion_point(field_set:LED_display.DISPLAY_MSG.dim_x)
}

// int32 dim_y = 4;
inline void DISPLAY_MSG::clear_dim_y() {
  dim_y_ = 0;
}
inline ::google::protobuf::int32 DISPLAY_MSG::dim_y() const {
  // @@protoc_insertion_point(field_get:LED_display.DISPLAY_MSG.dim_y)
  return dim_y_;
}
inline void DISPLAY_MSG::set_dim_y(::google::protobuf::int32 value) {
  
  dim_y_ = value;
  // @@protoc_insertion_point(field_set:LED_display.DISPLAY_MSG.dim_y)
}

// string pixel_list = 5;
inline void DISPLAY_MSG::clear_pixel_list() {
  pixel_list_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& DISPLAY_MSG::pixel_list() const {
  // @@protoc_insertion_point(field_get:LED_display.DISPLAY_MSG.pixel_list)
  return pixel_list_.GetNoArena();
}
inline void DISPLAY_MSG::set_pixel_list(const ::std::string& value) {
  
  pixel_list_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:LED_display.DISPLAY_MSG.pixel_list)
}
#if LANG_CXX11
inline void DISPLAY_MSG::set_pixel_list(::std::string&& value) {
  
  pixel_list_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:LED_display.DISPLAY_MSG.pixel_list)
}
#endif
inline void DISPLAY_MSG::set_pixel_list(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  pixel_list_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:LED_display.DISPLAY_MSG.pixel_list)
}
inline void DISPLAY_MSG::set_pixel_list(const char* value, size_t size) {
  
  pixel_list_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:LED_display.DISPLAY_MSG.pixel_list)
}
inline ::std::string* DISPLAY_MSG::mutable_pixel_list() {
  
  // @@protoc_insertion_point(field_mutable:LED_display.DISPLAY_MSG.pixel_list)
  return pixel_list_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* DISPLAY_MSG::release_pixel_list() {
  // @@protoc_insertion_point(field_release:LED_display.DISPLAY_MSG.pixel_list)
  
  return pixel_list_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void DISPLAY_MSG::set_allocated_pixel_list(::std::string* pixel_list) {
  if (pixel_list != NULL) {
    
  } else {
    
  }
  pixel_list_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), pixel_list);
  // @@protoc_insertion_point(field_set_allocated:LED_display.DISPLAY_MSG.pixel_list)
}

// -------------------------------------------------------------------

// DISPLAY_RESPONSE

// bool success = 1;
inline void DISPLAY_RESPONSE::clear_success() {
  success_ = false;
}
inline bool DISPLAY_RESPONSE::success() const {
  // @@protoc_insertion_point(field_get:LED_display.DISPLAY_RESPONSE.success)
  return success_;
}
inline void DISPLAY_RESPONSE::set_success(bool value) {
  
  success_ = value;
  // @@protoc_insertion_point(field_set:LED_display.DISPLAY_RESPONSE.success)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace LED_display

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_display_5fserver_2eproto__INCLUDED