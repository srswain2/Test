$.validator.setDefaults({submitHandler:function(){userManager.resetPass($("#oldPassword").val(),$("#password").val(),function(e){e.code===0?window.location.href="options.html?from=changePass":($("#msgAlert").html(e.msg),$("#msgAlert").show()),_gaq.push(["_trackEvent","Ext","changePass"])})}}),$().ready(function(){$("#changeForm").validate({rules:{password:{required:!0,minlength:6,maxlength:20},confirm_password:{required:!0,equalTo:"#password"},oldPassword:{required:!0,minlength:6,maxlength:20}},messages:{password:{required:"errNewEmailNeeded",minlength:"errNewPasswordShort",maxlength:"errorNewPasswordLong"},confirm_password:{required:"errConfirmPasswordNeeded",equalTo:"errConfirmPasswordNotSameNew"},oldPassword:{required:"errPasswordEmpty",minlength:"errPasswordShort",maxlength:"errPasswordTooLong"}}})});