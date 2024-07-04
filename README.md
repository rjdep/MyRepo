# Kubernetes Deployment for OCS Production in a New Namespace

This repository contains the Kubernetes configuration files for deploying the Oracle Container Signing (OCS) production environment in a newly created namespace. These configurations include resources such as `ConfigMaps`, `ServiceAccounts`, `Roles`, `RoleBindings`, `ClusterRoles`, `ClusterRoleBindings`, `LimitRanges`, and `IngressClasses`. The deployment is tailored to manage the NGINX Ingress Controller, Notary Signer, Notary Server, Sigsign Server and other essential components within the `ocs-prod` namespace.


## Pre-Requisites
- **Kubernetes Cluster**: A functioning Kubernetes cluster where the resources will be deployed [Kubernetes Cluster](https://docs.oracle.com/en-us/iaas/Content/ContEng/Concepts/contengoverview.htm)
- **Cluster Access**: Sufficient access rights to the cluster to create and manage namespaces and other resources. [Access Cluster](https://docs.oracle.com/en-us/iaas/Content/ContEng/Tasks/contengaccessingclusterkubectl.htm)
- **OCIR Repository Access**: Access to the Oracle Cloud Infrastructure Registry (OCIR) to pull necessary images for the deployment. [Container Registry](https://docs.oracle.com/en-us/iaas/Content/Registry/home.htm)



## Overview
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
- **Logging in to Oracle Cloud Infrastructure Registry**:
  ```bash
  docker login <region-key>.ocir.io
  ```
  where `region-key` can be found from [Availability by Region](https://docs.oracle.com/iaas/Content/Registry/Concepts/registryprerequisites.htm#regional-availability)
  
- **Username**:
  ```bash
  <tenancy-namespace>/<username>
  ```
  OR
  ```bash
  <tenancy-namespace>/oracleidentitycloudservice/<username>
  ```
  If your tenancy is federated with Oracle Identity Cloud Service
  
- **Getting an Auth Token**:
  To create a new authentication token:
    1. **Access User Settings**: Open the Console and click on your profile menu located in the top-right corner. Select "User Settings".
    2. **Generate Token**: In the User Settings, navigate to the "Auth Tokens" section and click on "Generate Token".
    3. **Describe Token**: Enter a brief, descriptive label for the new auth token. Avoid including sensitive information.
    4. **Generate and Copy**: Click "Generate Token" to create the new auth token. The token will appear on the screen.
    5. **Store Securely**: Immediately copy the auth token to a secure location. Once you close the dialog, the token will not be visible again in the Console.
    6. **Completion**: Close the "Generate Token" dialog when you have securely stored the auth token.

- **Pushing Images**:
  - To push an image, you first use the `docker tag` command to create a copy of the local source image as a new image
    ```bash
      <registry-domain>/<tenancy-namespace>/<repo-name>:<version>
    ```
    ```bash
      docker tag <image-identifier> <target-tag>
    ```
  - Push the image to OCIR repository
    ```bash
    docker push <target-tag>
    ```

- **Pulling Images from Container Registry during Kubernetes Deployment**:
  In the application's manifest file you specify the images to pull, the registry to pull them from, and the credentials to use when pulling the images.
  ```bash
  kubectl create secret generic regcred --namespace=ocs-prod --from-file=.dockerconfigjson=/root/.docker/config.json --type=kubernetes.io/dockerconfigjson
  ```

- **Deploying applications**:
  ```bash
  kubectl apply -f <file-name.yaml>
  ```

- **Kubectl Command**:
  - `describe`: The `describe` command provides detailed information about Kubernetes resources. It is used to troubleshoot and understand the current state of resources by displaying comprehensive metadata and status information.

    ```bash
      kubectl describe <resource-type> <resource-name>
    ```
  - `get`: The `get` command retrieves information about Kubernetes resources.

    ```bash
      kubectl get <resource-type>
    ```
  - `logs`: The `logs` command retrieves logs from containers running inside Pods. It is used for troubleshooting, monitoring applications, and checking application output.

    ```bash
      kubectl logs <pod-name> -n <namespace-name>
    ```
    

## References
- [Oracle Oci Oke Docs](https://oracle-terraform-modules.github.io/terraform-oci-oke/)
- [Accessing a Cluster Using Kubectl](https://docs.oracle.com/en-us/iaas/Content/ContEng/Tasks/contengaccessingclusterkubectl.htm)
- [Container Registry](https://docs.oracle.com/en-us/iaas/Content/Registry/home.htm)
- [Oracle Managed Kubernetes](https://docs.oracle.com/en/solutions/monitor-applications-on-kubernetes/deploy-application-oracle-managed-kubernetes-cluster.html#GUID-B2D9C6EC-DCDF-4BB7-B9C1-3493DA03A3FF)
- [Objects In Kubernetes](https://kubernetes.io/docs/concepts/overview/working-with-objects/)
