; Auto-generated. Do not edit!


(cl:in-package nao_basic-msg)


;//! \htmlinclude confirmation.msg.html

(cl:defclass <confirmation> (roslisp-msg-protocol:ros-message)
  ((name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (done
    :reader done
    :initarg :done
    :type cl:fixnum
    :initform 0))
)

(cl:defclass confirmation (<confirmation>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <confirmation>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'confirmation)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name nao_basic-msg:<confirmation> is deprecated: use nao_basic-msg:confirmation instead.")))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <confirmation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader nao_basic-msg:name-val is deprecated.  Use nao_basic-msg:name instead.")
  (name m))

(cl:ensure-generic-function 'done-val :lambda-list '(m))
(cl:defmethod done-val ((m <confirmation>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader nao_basic-msg:done-val is deprecated.  Use nao_basic-msg:done instead.")
  (done m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <confirmation>) ostream)
  "Serializes a message object of type '<confirmation>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:let* ((signed (cl:slot-value msg 'done)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <confirmation>) istream)
  "Deserializes a message object of type '<confirmation>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'done) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<confirmation>)))
  "Returns string type for a message object of type '<confirmation>"
  "nao_basic/confirmation")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'confirmation)))
  "Returns string type for a message object of type 'confirmation"
  "nao_basic/confirmation")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<confirmation>)))
  "Returns md5sum for a message object of type '<confirmation>"
  "c18f50469a1703e5916771c565e0a2ff")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'confirmation)))
  "Returns md5sum for a message object of type 'confirmation"
  "c18f50469a1703e5916771c565e0a2ff")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<confirmation>)))
  "Returns full string definition for message of type '<confirmation>"
  (cl:format cl:nil "string name~%int8 done~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'confirmation)))
  "Returns full string definition for message of type 'confirmation"
  (cl:format cl:nil "string name~%int8 done~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <confirmation>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'name))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <confirmation>))
  "Converts a ROS message object to a list"
  (cl:list 'confirmation
    (cl:cons ':name (name msg))
    (cl:cons ':done (done msg))
))
