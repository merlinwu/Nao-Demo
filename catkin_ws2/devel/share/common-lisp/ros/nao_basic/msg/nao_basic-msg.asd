
(cl:in-package :asdf)

(defsystem "nao_basic-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "activity" :depends-on ("_package_activity"))
    (:file "_package_activity" :depends-on ("_package"))
    (:file "confirmation" :depends-on ("_package_confirmation"))
    (:file "_package_confirmation" :depends-on ("_package"))
  ))