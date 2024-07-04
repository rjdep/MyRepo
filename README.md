# Kubernetes Deployment for OCS Production in a New Namespace

This repository contains the Kubernetes configuration files for deploying the Oracle Container Signing (OCS) production environment in a newly created namespace. These configurations include resources such as `ConfigMaps`, `ServiceAccounts`, `Roles`, `RoleBindings`, `ClusterRoles`, `ClusterRoleBindings`, `LimitRanges`, and `IngressClasses`. The deployment is tailored to manage the NGINX Ingress Controller, Notary Signer, Notary Server, Sigsign Server and other essential components within the `ocs-prod` namespace.


## Pre-Requisites
- **Kubernetes Cluster**: A functioning Kubernetes cluster where the resources will be deployed [Kubernetes Cluster](https://docs.oracle.com/en-us/iaas/Content/ContEng/Concepts/contengoverview.htm)
- **Cluster Access**: Sufficient access rights to the cluster to create and manage namespaces and other resources. [Access Cluster](https://docs.oracle.com/en-us/iaas/Content/ContEng/Tasks/contengaccessingclusterkubectl.htm)
- **OCIR Repository Access**: Access to the Oracle Cloud Infrastructure Registry (OCIR) to pull necessary images for the deployment. [Container Registry](https://docs.oracle.com/en-us/iaas/Content/Registry/home.htm)



## Gather Required Information
**Required Fields:**
- `Namespace`: A logical partition within a Kubernetes cluster that provides scope for names. It helps organize and manage resources, allowing for separate environments (e.g., development, staging, production) within the same cluster.
- `ConfigMap`: This ConfigMap contains key-value pairs used to customize the behavior of the controller.
- `tcp-services`: It provides configurations for services that require TCP load balancing.
- `udp-services`: It provides configurations for services that require UDP load balancing.
- `ServiceAccount`: ServiceAccount in Kubernetes is a special type of account that provides an identity for processes running within a Pod.
- `Role`: Defines a set of permissions within a specific namespace. It specifies what actions can be performed on which resources in that namespace.
- `ClusterRole`: Defines a set of permissions cluster-wide. It specifies what actions can be performed on which resources across all namespaces in the cluster.
- `RoleBinding`: Associates a Role with a ServiceAccount within a specific namespace, granting the permissions defined in the Role to that ServiceAccount.
- `ClusterRoleBinding`: Associates a ClusterRole with a ServiceAccount across the entire cluster, granting the permissions defined in the ClusterRole to that ServiceAccount.
- `RBAC rules`: Role-Based Access Control govern access permissions in Kubernetes, specifying which actions (verbs) are allowed on which resources (API groups, resources) by whom (subjects like users or ServiceAccounts).
- `app.kubernetes.io`:  Labels are a convention recommended by Kubernetes for metadata labels used to describe applications and their components within Kubernetes resources. They typically include components like `component`, `instance`, `name`, `part-of`, and `version`, aiding in better resource grouping, identification, and management within Kubernetes clusters.
- `Secrets`: It enables Kubernetes clusters to access private images stored in OCIR by securely managing and storing authentication credentials within the cluster, ensuring seamless integration of OCIR-hosted images into Kubernetes workloads.
- `Generic Secrets`: It provides a way to securely manage and access arbitrary sensitive information as base64-encoded data, supporting various use cases like configuration files, credentials, or other sensitive data needed by applications running in Kubernetes.
- `TLS Secret`: A type of Kubernetes Secret used to store TLS (Transport Layer Security) certificates and keys securely within the cluster. It enables secure communication over HTTPS or other TLS-based protocols by providing a way to manage and distribute TLS certificates to applications running in Kubernetes, ensuring data confidentiality and integrity.


## Setup and Run
Edit the `var.tf` file with the required Information.
Once the setup is done:
```bash
terraform init
```
```bash
terraform plan
```
```bash
terraform apply
```

## References
- [Oracle Oci Oke Docs](https://oracle-terraform-modules.github.io/terraform-oci-oke/)
- [Accessing a Cluster Using Kubectl](https://docs.oracle.com/en-us/iaas/Content/ContEng/Tasks/contengaccessingclusterkubectl.htm)
- [Terraform: Create a Kubernetes Cluster](https://docs.oracle.com/en-us/iaas/developer-tutorials/tutorials/tf-cluster/01-summary.htm)
