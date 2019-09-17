#
#  Be sure to run `pod spec lint Funambol.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  spec.name         = "Funambol"
  spec.version      = "0.0.1"
  spec.summary      = "Funambol For iOS & Macos."

  # This description is used to generate tags and improve search results.
  #   * Think: What does it do? Why did you write it? What is the focus?
  #   * Try to keep it short, snappy and to the point.
  #   * Write the description between the DESC delimiters below.
  #   * Finally, don't worry about the indent, CocoaPods strips it!
  spec.description  = <<-DESC
  Funambol For iOS & Macos.
                   DESC

  spec.homepage     = "http://www.github.com/wbitos/funambol"
  # spec.screenshots  = "www.example.com/screenshots_1.gif", "www.example.com/screenshots_2.gif"


  # ―――  Spec License  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Licensing your code is important. See https://choosealicense.com for more info.
  #  CocoaPods will detect a license file if there is a named LICENSE*
  #  Popular ones are 'MIT', 'BSD' and 'Apache License, Version 2.0'.
  #

  spec.license      = { :type => "MIT", :file => "LICENSE" }
  # spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }


  # ――― Author Metadata  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Specify the authors of the library, with email addresses. Email addresses
  #  of the authors are extracted from the SCM log. E.g. $ git log. CocoaPods also
  #  accepts just a name if you'd rather not provide an email address.
  #
  #  Specify a social_media_url where others can refer to, for example a twitter
  #  profile URL.
  #

  spec.author             = { "wbitos" => "wbitos@126.com" }
  # Or just: spec.author    = "wbitos"
  # spec.authors            = { "wbitos" => "wbitos@126.com" }
  # spec.social_media_url   = "https://twitter.com/wbitos"

  # ――― Platform Specifics ――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  If this Pod runs only on iOS or OS X, then specify the platform and
  #  the deployment target. You can optionally include the target after the platform.
  #

  # spec.platform     = :ios
  # spec.platform     = :ios, "5.0"

  #  When using multiple platforms
  # spec.ios.deployment_target = "5.0"
  # spec.osx.deployment_target = "10.7"
  # spec.watchos.deployment_target = "2.0"
  # spec.tvos.deployment_target = "9.0"

  spec.ios.deployment_target = "9.0"
  spec.osx.deployment_target = "10.9"
  spec.watchos.deployment_target = "2.0"
  spec.tvos.deployment_target = "9.0"


  src_root = '$(PODS_ROOT)/Funambol'
  
  spec.ios.pod_target_xcconfig = { 
    'FUNAMBOL_SRC_ROOT' => src_root,
    'HEADER_SEARCH_PATHS' => '"$(inherited)" "$(FUNAMBOL_SRC_ROOT)/Funambol/include"',
    'COMPILE_SOURCES_AS' => 'Objective-C++',
    'GCC_PREPROCESSOR_DEFINITIONS' => '"ENABLE_NAMESPACE" "FUNAMBOL_BUILD_API" "FUN_IPHONE"' 
  }
  spec.osx.pod_target_xcconfig = { 
    'FUNAMBOL_SRC_ROOT' => src_root,
    'HEADER_SEARCH_PATHS' => '"$(inherited)" "$(FUNAMBOL_SRC_ROOT)/include"',
    'COMPILE_SOURCES_AS' => 'Objective-C++',
    'GCC_PREPROCESSOR_DEFINITIONS' => '"ENABLE_NAMESPACE" "FUNAMBOL_BUILD_API"' 
  }
  spec.watchos.pod_target_xcconfig = { 
    'FUNAMBOL_SRC_ROOT' => src_root,
    'HEADER_SEARCH_PATHS' => '"$(inherited)" "$(FUNAMBOL_SRC_ROOT)/include"',
    'COMPILE_SOURCES_AS' => 'Objective-C++',
    'GCC_PREPROCESSOR_DEFINITIONS' => '"ENABLE_NAMESPACE" "FUNAMBOL_BUILD_API" "FUN_IPHONE"' 
  }
  spec.tvos.pod_target_xcconfig = { 
    'FUNAMBOL_SRC_ROOT' => src_root,
    'HEADER_SEARCH_PATHS' => '"$(inherited)" "$(FUNAMBOL_SRC_ROOT)/include"',
    'COMPILE_SOURCES_AS' => 'Objective-C++',
    'GCC_PREPROCESSOR_DEFINITIONS' => '"ENABLE_NAMESPACE" "FUNAMBOL_BUILD_API" "FUN_IPHONE"' 
  }

  # ――― Source Location ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Specify the location from where the source should be retrieved.
  #  Supports git, hg, bzr, svn and HTTP.
  #

  spec.source       = { :git => "https://github.com/wbitos/funambol.git", :tag => "#{spec.version}" }

  spec.module_map = 'Funambol.modulemap'
  spec.libraries = 'c++'
  # ――― Source Code ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  CocoaPods is smart about how it includes source code. For source files
  #  giving a folder will include any swift, h, m, mm, c & cpp files.
  #  For header files it will include any header in the folder.
  #  Not including the public_header_files will make all headers public.
  #

  spec.source_files  = 'Funambol/include/Funambol/base/adapter/PlatformAdapter.h',
'Funambol/include/Funambol/base/base64.h',
'Funambol/include/Funambol/base/cJSON.h',
'Funambol/include/Funambol/base/constants.h',
'Funambol/include/Funambol/base/debug.h',
'Funambol/include/Funambol/base/ErrorReport.h',
'Funambol/include/Funambol/base/errors.h',
'Funambol/include/Funambol/base/fscapi.h',
'Funambol/include/Funambol/base/globalsdef.h',
'Funambol/include/Funambol/base/Log.h',
'Funambol/include/Funambol/base/md5.h',
'Funambol/include/Funambol/base/messages.h',
'Funambol/include/Funambol/base/posix_build_adapter.h',
'Funambol/include/Funambol/base/posixadapter.h',
'Funambol/include/Funambol/base/posixlog.h',
'Funambol/include/Funambol/base/quoted-printable.h',
'Funambol/include/Funambol/base/util/ArrayElement.h',
'Funambol/include/Funambol/base/util/ArrayList.h',
'Funambol/include/Funambol/base/util/ArrayListEnumeration.h',
'Funambol/include/Funambol/base/util/BasicTime.h',
'Funambol/include/Funambol/base/util/EncodingHelper.h',
'Funambol/include/Funambol/base/util/Enumeration.h',
'Funambol/include/Funambol/base/util/ItemContainer.h',
'Funambol/include/Funambol/base/util/KeyValuePair.h',
'Funambol/include/Funambol/base/util/KeyValueStore.h',
'Funambol/include/Funambol/base/util/MemoryKeyValueStore.h',
'Funambol/include/Funambol/base/util/PropertyFile.h',
'Funambol/include/Funambol/base/util/StringBuffer.h',
'Funambol/include/Funambol/base/util/StringMap.h',
'Funambol/include/Funambol/base/util/stringUtils.h',
'Funambol/include/Funambol/base/util/utils.h',
'Funambol/include/Funambol/base/util/WKeyValuePair.h',
'Funambol/include/Funambol/base/util/WString.h',
'Funambol/include/Funambol/base/util/XMLProcessor.h',
'Funambol/include/Funambol/client/CacheSyncSource.h',
'Funambol/include/Funambol/client/ConfigSyncSource.h',
'Funambol/include/Funambol/client/DMTClientConfig.h',
'Funambol/include/Funambol/client/SQLiteKeyValueStore.h',
'Funambol/include/Funambol/client/SQLKeyValueStore.h',
'Funambol/include/Funambol/client/SyncClient.h',
'Funambol/include/Funambol/event/BaseEvent.h',
'Funambol/include/Funambol/event/constants.h',
'Funambol/include/Funambol/event/FireEvent.h',
'Funambol/include/Funambol/event/Listener.h',
'Funambol/include/Funambol/event/ManageListener.h',
'Funambol/include/Funambol/event/SetListener.h',
'Funambol/include/Funambol/event/SyncEvent.h',
'Funambol/include/Funambol/event/SyncItemEvent.h',
'Funambol/include/Funambol/event/SyncItemListener.h',
'Funambol/include/Funambol/event/SyncListener.h',
'Funambol/include/Funambol/event/SyncSourceEvent.h',
'Funambol/include/Funambol/event/SyncSourceListener.h',
'Funambol/include/Funambol/event/SyncStatusEvent.h',
'Funambol/include/Funambol/event/SyncStatusListener.h',
'Funambol/include/Funambol/event/TransportEvent.h',
'Funambol/include/Funambol/event/TransportListener.h',
'Funambol/include/Funambol/filter/AllClause.h',
'Funambol/include/Funambol/filter/Clause.h',
'Funambol/include/Funambol/filter/ClauseUtil.h',
'Funambol/include/Funambol/filter/FieldClause.h',
'Funambol/include/Funambol/filter/LogicalClause.h',
'Funambol/include/Funambol/filter/SourceFilter.h',
'Funambol/include/Funambol/filter/WhereClause.h',
'Funambol/include/Funambol/http/AbstractHttpConnection.h',
'Funambol/include/Funambol/http/BasicAuthentication.h',
'Funambol/include/Funambol/http/constants.h',
'Funambol/include/Funambol/http/CustomTransportAgent.h',
'Funambol/include/Funambol/http/DigestAuthentication.h',
'Funambol/include/Funambol/http/errors.h',
'Funambol/include/Funambol/http/HashProvider.h',
'Funambol/include/Funambol/http/HttpAuthentication.h',
'Funambol/include/Funambol/http/HttpConnection.h',
'Funambol/include/Funambol/http/HttpConnectionHandler.h',
'Funambol/include/Funambol/http/HTTPHeader.h',
'Funambol/include/Funambol/http/HttpUploader.h',
'Funambol/include/Funambol/http/MacTransportAgent.h',
'Funambol/include/Funambol/http/Proxy.h',
'Funambol/include/Funambol/http/TransportAgent.h',
'Funambol/include/Funambol/http/TransportAgentFactory.h',
'Funambol/include/Funambol/http/URL.h',
'Funambol/include/Funambol/inputStream/AppleBufferInputStream.h',
'Funambol/include/Funambol/inputStream/AppleFileInputStream.h',
'Funambol/include/Funambol/inputStream/AppleInputStream.h',
'Funambol/include/Funambol/inputStream/BoundaryInputStream.h',
'Funambol/include/Funambol/inputStream/BufferInputStream.h',
'Funambol/include/Funambol/inputStream/BufferOutputStream.h',
'Funambol/include/Funambol/inputStream/FileDataInputStream.h',
'Funambol/include/Funambol/inputStream/FileInputStream.h',
'Funambol/include/Funambol/inputStream/InputStream.h',
'Funambol/include/Funambol/inputStream/MultipleInputStream.h',
'Funambol/include/Funambol/inputStream/OutputStream.h',
'Funambol/include/Funambol/inputStream/StringOutputStream.h',
'Funambol/include/Funambol/msu/JsonMSUMessage.h',
'Funambol/include/Funambol/msu/MSUDeviceInfo.h',
'Funambol/include/Funambol/msu/MSUManager.h',
'Funambol/include/Funambol/push/CTPConfig.h',
'Funambol/include/Funambol/push/CTPMessage.h',
'Funambol/include/Funambol/push/CTPParam.h',
'Funambol/include/Funambol/push/CTPService.h',
'Funambol/include/Funambol/push/CTPThreadPool.h',
'Funambol/include/Funambol/push/FSocket.h',
'Funambol/include/Funambol/push/FThread.h',
'Funambol/include/Funambol/push/PushListener.h',
'Funambol/include/Funambol/spdm/constants.h',
'Funambol/include/Funambol/spdm/DeviceManagementNode.h',
'Funambol/include/Funambol/spdm/DeviceManager.h',
'Funambol/include/Funambol/spdm/DeviceManagerFactory.h',
'Funambol/include/Funambol/spdm/DMTree.h',
'Funambol/include/Funambol/spdm/DMTreeFactory.h',
'Funambol/include/Funambol/spdm/errors.h',
'Funambol/include/Funambol/spdm/ManagementNode.h',
'Funambol/include/Funambol/spdm/migrateConfig.h',
'Funambol/include/Funambol/spdm/spdmutils.h',
'Funambol/include/Funambol/spds/AbstractSyncConfig.h',
'Funambol/include/Funambol/spds/AbstractSyncSourceConfig.h',
'Funambol/include/Funambol/spds/AccessConfig.h',
'Funambol/include/Funambol/spds/B64Decoder.h',
'Funambol/include/Funambol/spds/B64Encoder.h',
'Funambol/include/Funambol/spds/BodyPart.h',
'Funambol/include/Funambol/spds/BoundarySyncItem.h',
'Funambol/include/Funambol/spds/Chunk.h',
'Funambol/include/Funambol/spds/constants.h',
'Funambol/include/Funambol/spds/CredentialHandler.h',
'Funambol/include/Funambol/spds/DataTransformer.h',
'Funambol/include/Funambol/spds/DataTransformerFactory.h',
'Funambol/include/Funambol/spds/DefaultConfigFactory.h',
'Funambol/include/Funambol/spds/DESDecoder.h',
'Funambol/include/Funambol/spds/DESEncoder.h',
'Funambol/include/Funambol/spds/DeviceConfig.h',
'Funambol/include/Funambol/spds/Email.h',
'Funambol/include/Funambol/spds/EmailData.h',
'Funambol/include/Funambol/spds/errors.h',
'Funambol/include/Funambol/spds/FileData.h',
'Funambol/include/Funambol/spds/FolderData.h',
'Funambol/include/Funambol/spds/FolderExt.h',
'Funambol/include/Funambol/spds/ItemReader.h',
'Funambol/include/Funambol/spds/ItemReport.h',
'Funambol/include/Funambol/spds/MappingsManager.h',
'Funambol/include/Funambol/spds/MappingStoreBuilder.h',
'Funambol/include/Funambol/spds/spdsutils.h',
'Funambol/include/Funambol/spds/SyncItem.h',
'Funambol/include/Funambol/spds/SyncItemKeys.h',
'Funambol/include/Funambol/spds/SyncItemStatus.h',
'Funambol/include/Funambol/spds/SyncManager.h',
'Funambol/include/Funambol/spds/SyncManagerConfig.h',
'Funambol/include/Funambol/spds/SyncMap.h',
'Funambol/include/Funambol/spds/SyncMLBuilder.h',
'Funambol/include/Funambol/spds/SyncMLProcessor.h',
'Funambol/include/Funambol/spds/SyncReport.h',
'Funambol/include/Funambol/spds/SyncSource.h',
'Funambol/include/Funambol/spds/SyncSourceConfig.h',
'Funambol/include/Funambol/spds/SyncSourceReport.h',
'Funambol/include/Funambol/spds/SyncStatus.h',
'Funambol/include/Funambol/syncml/core/AbstractCommand.h',
'Funambol/include/Funambol/syncml/core/Add.h',
'Funambol/include/Funambol/syncml/core/Alert.h',
'Funambol/include/Funambol/syncml/core/AlertCode.h',
'Funambol/include/Funambol/syncml/core/Anchor.h',
'Funambol/include/Funambol/syncml/core/Atomic.h',
'Funambol/include/Funambol/syncml/core/Authentication.h',
'Funambol/include/Funambol/syncml/core/Chal.h',
'Funambol/include/Funambol/syncml/core/CmdID.h',
'Funambol/include/Funambol/syncml/core/ComplexData.h',
'Funambol/include/Funambol/syncml/core/Constants.h',
'Funambol/include/Funambol/syncml/core/ContentTypeInfo.h',
'Funambol/include/Funambol/syncml/core/ContentTypeParameter.h',
'Funambol/include/Funambol/syncml/core/Copy.h',
'Funambol/include/Funambol/syncml/core/core.h',
'Funambol/include/Funambol/syncml/core/Cred.h',
'Funambol/include/Funambol/syncml/core/CTCap.h',
'Funambol/include/Funambol/syncml/core/CTPropParam.h',
'Funambol/include/Funambol/syncml/core/CTTypeSupported.h',
'Funambol/include/Funambol/syncml/core/Data.h',
'Funambol/include/Funambol/syncml/core/DataStore.h',
'Funambol/include/Funambol/syncml/core/Delete.h',
'Funambol/include/Funambol/syncml/core/DevInf.h',
'Funambol/include/Funambol/syncml/core/DevInfData.h',
'Funambol/include/Funambol/syncml/core/DevInfItem.h',
'Funambol/include/Funambol/syncml/core/DevTyp.h',
'Funambol/include/Funambol/syncml/core/DSMem.h',
'Funambol/include/Funambol/syncml/core/EMI.h',
'Funambol/include/Funambol/syncml/core/Exec.h',
'Funambol/include/Funambol/syncml/core/Ext.h',
'Funambol/include/Funambol/syncml/core/Filter.h',
'Funambol/include/Funambol/syncml/core/Get.h',
'Funambol/include/Funambol/syncml/core/Item.h',
'Funambol/include/Funambol/syncml/core/ItemizedCommand.h',
'Funambol/include/Funambol/syncml/core/Map.h',
'Funambol/include/Funambol/syncml/core/MapItem.h',
'Funambol/include/Funambol/syncml/core/Mark.h',
'Funambol/include/Funambol/syncml/core/Mem.h',
'Funambol/include/Funambol/syncml/core/Meta.h',
'Funambol/include/Funambol/syncml/core/MetInf.h',
'Funambol/include/Funambol/syncml/core/ModificationCommand.h',
'Funambol/include/Funambol/syncml/core/NextNonce.h',
'Funambol/include/Funambol/syncml/core/ObjectDel.h',
'Funambol/include/Funambol/syncml/core/Property.h',
'Funambol/include/Funambol/syncml/core/PropParam.h',
'Funambol/include/Funambol/syncml/core/Put.h',
'Funambol/include/Funambol/syncml/core/Replace.h',
'Funambol/include/Funambol/syncml/core/ResponseCommand.h',
'Funambol/include/Funambol/syncml/core/Results.h',
'Funambol/include/Funambol/syncml/core/Search.h',
'Funambol/include/Funambol/syncml/core/Sequence.h',
'Funambol/include/Funambol/syncml/core/SessionID.h',
'Funambol/include/Funambol/syncml/core/Source.h',
'Funambol/include/Funambol/syncml/core/SourceArray.h',
'Funambol/include/Funambol/syncml/core/SourceRef.h',
'Funambol/include/Funambol/syncml/core/Status.h',
'Funambol/include/Funambol/syncml/core/StringElement.h',
'Funambol/include/Funambol/syncml/core/Sync.h',
'Funambol/include/Funambol/syncml/core/SyncAlert.h',
'Funambol/include/Funambol/syncml/core/SyncBody.h',
'Funambol/include/Funambol/syncml/core/SyncCap.h',
'Funambol/include/Funambol/syncml/core/SyncHdr.h',
'Funambol/include/Funambol/syncml/core/SyncML.h',
'Funambol/include/Funambol/syncml/core/SyncNotification.h',
'Funambol/include/Funambol/syncml/core/SyncType.h',
'Funambol/include/Funambol/syncml/core/SyncTypeArray.h',
'Funambol/include/Funambol/syncml/core/TagNames.h',
'Funambol/include/Funambol/syncml/core/Target.h',
'Funambol/include/Funambol/syncml/core/TargetRef.h',
'Funambol/include/Funambol/syncml/core/VerDTD.h',
'Funambol/include/Funambol/syncml/core/VerProto.h',
'Funambol/include/Funambol/syncml/formatter/Formatter.h',
'Funambol/include/Funambol/syncml/parser/Parser.h',
'Funambol/include/Funambol/updater/Updater.h',
'Funambol/include/Funambol/updater/UpdaterConfig.h',
'Funambol/include/Funambol/updater/UpdaterUI.h',
"Funambol/source/apple/**/*.{m,mm,c,cpp}", 
"Funambol/source/common/**/*.{m,mm,c,cpp}", 
"Funambol/source/posix/**/*.{m,mm,c,cpp}"
  #spec.exclude_files = "Classes/Exclude"

  # spec.public_header_files = "Classes/**/*.h"
  spec.header_dir = "Funambol"
  spec.header_mappings_dir = 'Funambol/include'

  # ――― Resources ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  A list of resources included with the Pod. These are copied into the
  #  target bundle with a build phase script. Anything else will be cleaned.
  #  You can preserve files from being cleaned, please don't preserve
  #  non-essential files like tests, examples and documentation.
  #

  # spec.resource  = "icon.png"
  # spec.resources = "Resources/*.png"

  # spec.preserve_paths = "FilesToSave", "MoreFilesToSave"


  # ――― Project Linking ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Link your library with frameworks, or libraries. Libraries do not include
  #  the lib prefix of their name.
  #

  # spec.framework  = "SomeFramework"
  # spec.frameworks = "SomeFramework", "AnotherFramework"

  # spec.library   = "iconv"
  # spec.libraries = "iconv", "xml2"


  # ――― Project Settings ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  If your library depends on compiler flags you can set them in the xcconfig hash
  #  where they will only apply to your library. If you depend on other Podspecs
  #  you can include multiple dependencies to ensure it works.

  # spec.requires_arc = true
  spec.requires_arc = false

  # spec.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # spec.dependency "JSONKit", "~> 1.4"
  spec.dependency "GZIP"
end
