#ifndef GEOMETRY_UTILITY_H
#define GEOMETRY_UTILITY_H

//-- includes -----
#undef Status
#undef Success
#include <opencv2/opencv.hpp>
#include "MathEigen.h"
#include "ClientGeometry_CAPI.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>

//-- methods -----
// PSMove types to PSMove Types
PSMQuatf psm_matrix3f_to_psm_quatf(const PSMMatrix3f &m);
PSMMatrix3f psm_quatf_to_psm_matrix3f(const PSMQuatf &q);

// PSMove types to GLM types
glm::vec3 psm_vector3f_to_glm_vec3(const PSMVector3f &v);
glm::quat psm_quatf_to_glm_quat(const PSMQuatf &q);
glm::mat3 psm_matrix3f_to_glm_mat3(const PSMMatrix3f &m);
glm::mat4 psm_posef_to_glm_mat4(const PSMQuatf &quat, const PSMVector3f &pos);
glm::mat4 psm_posef_to_glm_mat4(const PSMPosef &pose);

// GLM Types to PSMove types
PSMVector3f glm_vec3_to_psm_vector3f(const glm::vec3 &v);
PSMMatrix3f glm_mat3_to_psm_matrix3f(const glm::mat3 &m);
PSMQuatf glm_mat3_to_psm_quatf(const glm::quat &q);
PSMPosef glm_mat4_to_psm_posef(const glm::mat4 &m);

// GLM Types to Eigen types
Eigen::Matrix3f glm_mat3_to_eigen_matrix3f(const glm::mat3 &m);
Eigen::Matrix4f glm_mat4_to_eigen_matrix4f(const glm::mat4 &m);

// PSMove types to OpenCV types
cv::Matx33f psmove_matrix3x3_to_cv_mat33f(const PSMMatrix3f &in);
cv::Matx33f psmove_matrix3x3_to_cv_mat33f(const PSMMatrix3d &in);
cv::Matx33d psmove_matrix3x3_to_cv_mat33d(const PSMMatrix3d &in);
cv::Matx34d psmove_matrix3x4_to_cv_mat34d(const PSMMatrix34d &in);
cv::Matx44d psmove_matrix4x4_to_cv_mat44d(const PSMMatrix4d &in);
cv::Vec3d psmove_vector3d_to_cv_vec3d(const PSMVector3d &in);

// OpenCV types to PSMove types
PSMMatrix3f cv_mat33f_to_psm_matrix3x3(const cv::Matx33f &in);
PSMMatrix3d cv_mat33d_to_psm_matrix3x3(const cv::Matx33d &in);
PSMMatrix4d cv_mat44d_to_psm_matrix4x4(const cv::Matx44d &in);
PSMMatrix34d cv_mat34d_to_psm_matrix3x4(const cv::Matx34d &in);
PSMVector3d cv_vec3d_to_psm_vector3d(const cv::Vec3d &in);

// PSMoveTypes to Eigen types
Eigen::Vector3f psm_vector3i_to_eigen_vector3(const PSMVector3i &v);
Eigen::Vector3f psm_vector3f_to_eigen_vector3(const PSMVector3f &p);
Eigen::Vector3f psm_vector3f_to_eigen_vector3(const PSMVector3f &v);
Eigen::Quaternionf psm_quatf_to_eigen_quaternionf(const PSMQuatf &q);
Eigen::Matrix3f psm_matrix3f_to_eigen_matrix3(const PSMMatrix3f &m);
Eigen::Matrix3f psm_matrix3d_to_eigen_matrix3f(const PSMMatrix3d &m);
Eigen::Matrix4f psm_matrix4d_to_eigen_matrix4f(const PSMMatrix4d &m);
Eigen::Matrix4d psm_matrix4d_to_eigen_matrix4d(const PSMMatrix4d &m);

// Eigen types to GLM types
glm::mat3 eigen_matrix3f_to_glm_mat3(const Eigen::Matrix3f &m);
glm::mat4 eigen_matrix4f_to_glm_mat4(const Eigen::Matrix4f &m);
glm::vec3 eigen_vector3f_to_glm_vec3(const Eigen::Vector3f &v);

// Eigen types to PSMove types
PSMVector3f eigen_vector3f_to_psm_vector3f(const Eigen::Vector3f &v);

#endif // GEOMETRY_UTILITY_H