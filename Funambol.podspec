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

  spec.ios.pod_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => 'ENABLE_NAMESPACE' 'FUNAMBOL_BUILD_API' 'FUN_IPHONE' }
  spec.osx.pod_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => 'ENABLE_NAMESPACE' 'FUNAMBOL_BUILD_API' }
  spec.watchos.pod_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => 'ENABLE_NAMESPACE' 'FUNAMBOL_BUILD_API' 'FUN_IPHONE' }
  spec.tvos.pod_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => 'ENABLE_NAMESPACE' 'FUNAMBOL_BUILD_API' 'FUN_IPHONE' }

  # ――― Source Location ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Specify the location from where the source should be retrieved.
  #  Supports git, hg, bzr, svn and HTTP.
  #

  spec.source       = { :git => "https://github.com/wbitos/funambol.git", :tag => "#{spec.version}" }


  spec.libraries = 'c++'
  # ――― Source Code ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  CocoaPods is smart about how it includes source code. For source files
  #  giving a folder will include any swift, h, m, mm, c & cpp files.
  #  For header files it will include any header in the folder.
  #  Not including the public_header_files will make all headers public.
  #

  spec.source_files  = 'Funambol/include/base/adapter/PlatformAdapter.h',
'Funambol/include/base/base64.h',
'Funambol/include/base/cJSON.h',
'Funambol/include/base/constants.h',
'Funambol/include/base/debug.h',
'Funambol/include/base/ErrorReport.h',
'Funambol/include/base/errors.h',
'Funambol/include/base/fscapi.h',
'Funambol/include/base/globalsdef.h',
'Funambol/include/base/Log.h',
'Funambol/include/base/md5.h',
'Funambol/include/base/messages.h',
'Funambol/include/base/posix_build_adapter.h',
'Funambol/include/base/posixadapter.h',
'Funambol/include/base/posixlog.h',
'Funambol/include/base/quoted-printable.h',
'Funambol/include/base/util/ArrayElement.h',
'Funambol/include/base/util/ArrayList.h',
'Funambol/include/base/util/ArrayListEnumeration.h',
'Funambol/include/base/util/BasicTime.h',
'Funambol/include/base/util/EncodingHelper.h',
'Funambol/include/base/util/Enumeration.h',
'Funambol/include/base/util/ItemContainer.h',
'Funambol/include/base/util/KeyValuePair.h',
'Funambol/include/base/util/KeyValueStore.h',
'Funambol/include/base/util/MemoryKeyValueStore.h',
'Funambol/include/base/util/PropertyFile.h',
'Funambol/include/base/util/StringBuffer.h',
'Funambol/include/base/util/StringMap.h',
'Funambol/include/base/util/stringUtils.h',
'Funambol/include/base/util/utils.h',
'Funambol/include/base/util/WKeyValuePair.h',
'Funambol/include/base/util/WString.h',
'Funambol/include/base/util/XMLProcessor.h',
'Funambol/include/client/CacheSyncSource.h',
'Funambol/include/client/ConfigSyncSource.h',
'Funambol/include/client/DMTClientConfig.h',
'Funambol/include/client/SQLiteKeyValueStore.h',
'Funambol/include/client/SQLKeyValueStore.h',
'Funambol/include/client/SyncClient.h',
'Funambol/include/event/BaseEvent.h',
'Funambol/include/event/constants.h',
'Funambol/include/event/FireEvent.h',
'Funambol/include/event/Listener.h',
'Funambol/include/event/ManageListener.h',
'Funambol/include/event/SetListener.h',
'Funambol/include/event/SyncEvent.h',
'Funambol/include/event/SyncItemEvent.h',
'Funambol/include/event/SyncItemListener.h',
'Funambol/include/event/SyncListener.h',
'Funambol/include/event/SyncSourceEvent.h',
'Funambol/include/event/SyncSourceListener.h',
'Funambol/include/event/SyncStatusEvent.h',
'Funambol/include/event/SyncStatusListener.h',
'Funambol/include/event/TransportEvent.h',
'Funambol/include/event/TransportListener.h',
'Funambol/include/filter/AllClause.h',
'Funambol/include/filter/Clause.h',
'Funambol/include/filter/ClauseUtil.h',
'Funambol/include/filter/FieldClause.h',
'Funambol/include/filter/LogicalClause.h',
'Funambol/include/filter/SourceFilter.h',
'Funambol/include/filter/WhereClause.h',
'Funambol/include/http/AbstractHttpConnection.h',
'Funambol/include/http/BasicAuthentication.h',
'Funambol/include/http/constants.h',
'Funambol/include/http/CustomTransportAgent.h',
'Funambol/include/http/DigestAuthentication.h',
'Funambol/include/http/errors.h',
'Funambol/include/http/HashProvider.h',
'Funambol/include/http/HttpAuthentication.h',
'Funambol/include/http/HttpConnection.h',
'Funambol/include/http/HttpConnectionHandler.h',
'Funambol/include/http/HTTPHeader.h',
'Funambol/include/http/HttpUploader.h',
'Funambol/include/http/MacTransportAgent.h',
'Funambol/include/http/Proxy.h',
'Funambol/include/http/TransportAgent.h',
'Funambol/include/http/TransportAgentFactory.h',
'Funambol/include/http/URL.h',
'Funambol/include/inputStream/AppleBufferInputStream.h',
'Funambol/include/inputStream/AppleFileInputStream.h',
'Funambol/include/inputStream/AppleInputStream.h',
'Funambol/include/inputStream/BoundaryInputStream.h',
'Funambol/include/inputStream/BufferInputStream.h',
'Funambol/include/inputStream/BufferOutputStream.h',
'Funambol/include/inputStream/FileDataInputStream.h',
'Funambol/include/inputStream/FileInputStream.h',
'Funambol/include/inputStream/InputStream.h',
'Funambol/include/inputStream/MultipleInputStream.h',
'Funambol/include/inputStream/OutputStream.h',
'Funambol/include/inputStream/StringOutputStream.h',
'Funambol/include/msu/JsonMSUMessage.h',
'Funambol/include/msu/MSUDeviceInfo.h',
'Funambol/include/msu/MSUManager.h',
'Funambol/include/push/CTPConfig.h',
'Funambol/include/push/CTPMessage.h',
'Funambol/include/push/CTPParam.h',
'Funambol/include/push/CTPService.h',
'Funambol/include/push/CTPThreadPool.h',
'Funambol/include/push/FSocket.h',
'Funambol/include/push/FThread.h',
'Funambol/include/push/PushListener.h',
'Funambol/include/spdm/constants.h',
'Funambol/include/spdm/DeviceManagementNode.h',
'Funambol/include/spdm/DeviceManager.h',
'Funambol/include/spdm/DeviceManagerFactory.h',
'Funambol/include/spdm/DMTree.h',
'Funambol/include/spdm/DMTreeFactory.h',
'Funambol/include/spdm/errors.h',
'Funambol/include/spdm/ManagementNode.h',
'Funambol/include/spdm/migrateConfig.h',
'Funambol/include/spdm/spdmutils.h',
'Funambol/include/spds/AbstractSyncConfig.h',
'Funambol/include/spds/AbstractSyncSourceConfig.h',
'Funambol/include/spds/AccessConfig.h',
'Funambol/include/spds/B64Decoder.h',
'Funambol/include/spds/B64Encoder.h',
'Funambol/include/spds/BodyPart.h',
'Funambol/include/spds/BoundarySyncItem.h',
'Funambol/include/spds/Chunk.h',
'Funambol/include/spds/constants.h',
'Funambol/include/spds/CredentialHandler.h',
'Funambol/include/spds/DataTransformer.h',
'Funambol/include/spds/DataTransformerFactory.h',
'Funambol/include/spds/DefaultConfigFactory.h',
'Funambol/include/spds/DESDecoder.h',
'Funambol/include/spds/DESEncoder.h',
'Funambol/include/spds/DeviceConfig.h',
'Funambol/include/spds/Email.h',
'Funambol/include/spds/EmailData.h',
'Funambol/include/spds/errors.h',
'Funambol/include/spds/FileData.h',
'Funambol/include/spds/FolderData.h',
'Funambol/include/spds/FolderExt.h',
'Funambol/include/spds/ItemReader.h',
'Funambol/include/spds/ItemReport.h',
'Funambol/include/spds/MappingsManager.h',
'Funambol/include/spds/MappingStoreBuilder.h',
'Funambol/include/spds/spdsutils.h',
'Funambol/include/spds/SyncItem.h',
'Funambol/include/spds/SyncItemKeys.h',
'Funambol/include/spds/SyncItemStatus.h',
'Funambol/include/spds/SyncManager.h',
'Funambol/include/spds/SyncManagerConfig.h',
'Funambol/include/spds/SyncMap.h',
'Funambol/include/spds/SyncMLBuilder.h',
'Funambol/include/spds/SyncMLProcessor.h',
'Funambol/include/spds/SyncReport.h',
'Funambol/include/spds/SyncSource.h',
'Funambol/include/spds/SyncSourceConfig.h',
'Funambol/include/spds/SyncSourceReport.h',
'Funambol/include/spds/SyncStatus.h',
'Funambol/include/syncml/core/AbstractCommand.h',
'Funambol/include/syncml/core/Add.h',
'Funambol/include/syncml/core/Alert.h',
'Funambol/include/syncml/core/AlertCode.h',
'Funambol/include/syncml/core/Anchor.h',
'Funambol/include/syncml/core/Atomic.h',
'Funambol/include/syncml/core/Authentication.h',
'Funambol/include/syncml/core/Chal.h',
'Funambol/include/syncml/core/CmdID.h',
'Funambol/include/syncml/core/ComplexData.h',
'Funambol/include/syncml/core/Constants.h',
'Funambol/include/syncml/core/ContentTypeInfo.h',
'Funambol/include/syncml/core/ContentTypeParameter.h',
'Funambol/include/syncml/core/Copy.h',
'Funambol/include/syncml/core/core.h',
'Funambol/include/syncml/core/Cred.h',
'Funambol/include/syncml/core/CTCap.h',
'Funambol/include/syncml/core/CTPropParam.h',
'Funambol/include/syncml/core/CTTypeSupported.h',
'Funambol/include/syncml/core/Data.h',
'Funambol/include/syncml/core/DataStore.h',
'Funambol/include/syncml/core/Delete.h',
'Funambol/include/syncml/core/DevInf.h',
'Funambol/include/syncml/core/DevInfData.h',
'Funambol/include/syncml/core/DevInfItem.h',
'Funambol/include/syncml/core/DevTyp.h',
'Funambol/include/syncml/core/DSMem.h',
'Funambol/include/syncml/core/EMI.h',
'Funambol/include/syncml/core/Exec.h',
'Funambol/include/syncml/core/Ext.h',
'Funambol/include/syncml/core/Filter.h',
'Funambol/include/syncml/core/Get.h',
'Funambol/include/syncml/core/Item.h',
'Funambol/include/syncml/core/ItemizedCommand.h',
'Funambol/include/syncml/core/Map.h',
'Funambol/include/syncml/core/MapItem.h',
'Funambol/include/syncml/core/Mark.h',
'Funambol/include/syncml/core/Mem.h',
'Funambol/include/syncml/core/Meta.h',
'Funambol/include/syncml/core/MetInf.h',
'Funambol/include/syncml/core/ModificationCommand.h',
'Funambol/include/syncml/core/NextNonce.h',
'Funambol/include/syncml/core/ObjectDel.h',
'Funambol/include/syncml/core/Property.h',
'Funambol/include/syncml/core/PropParam.h',
'Funambol/include/syncml/core/Put.h',
'Funambol/include/syncml/core/Replace.h',
'Funambol/include/syncml/core/ResponseCommand.h',
'Funambol/include/syncml/core/Results.h',
'Funambol/include/syncml/core/Search.h',
'Funambol/include/syncml/core/Sequence.h',
'Funambol/include/syncml/core/SessionID.h',
'Funambol/include/syncml/core/Source.h',
'Funambol/include/syncml/core/SourceArray.h',
'Funambol/include/syncml/core/SourceRef.h',
'Funambol/include/syncml/core/Status.h',
'Funambol/include/syncml/core/StringElement.h',
'Funambol/include/syncml/core/Sync.h',
'Funambol/include/syncml/core/SyncAlert.h',
'Funambol/include/syncml/core/SyncBody.h',
'Funambol/include/syncml/core/SyncCap.h',
'Funambol/include/syncml/core/SyncHdr.h',
'Funambol/include/syncml/core/SyncML.h',
'Funambol/include/syncml/core/SyncNotification.h',
'Funambol/include/syncml/core/SyncType.h',
'Funambol/include/syncml/core/SyncTypeArray.h',
'Funambol/include/syncml/core/TagNames.h',
'Funambol/include/syncml/core/Target.h',
'Funambol/include/syncml/core/TargetRef.h',
'Funambol/include/syncml/core/VerDTD.h',
'Funambol/include/syncml/core/VerProto.h',
'Funambol/include/syncml/formatter/Formatter.h',
'Funambol/include/syncml/parser/Parser.h',
'Funambol/include/updater/Updater.h',
'Funambol/include/updater/UpdaterConfig.h',
'Funambol/include/updater/UpdaterUI.h',
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

  # spec.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # spec.dependency "JSONKit", "~> 1.4"
  spec.dependency "GZIP"
end
